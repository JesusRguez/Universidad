/*
 * Copyright (c) 2016 Pablo Neira Ayuso <pablo@netfilter.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/atomic.h>
#include <linux/netlink.h>
#include <linux/netfilter.h>
#include <linux/netfilter/nf_tables.h>
#include <net/netfilter/nf_tables.h>

struct nft_quota {
	u64		quota;
	unsigned long	flags;
	atomic64_t	consumed;
};

static inline bool nft_overquota(struct nft_quota *priv,
				 const struct sk_buff *skb)
{
	return atomic64_add_return(skb->len, &priv->consumed) >= priv->quota;
}

static inline bool nft_quota_invert(struct nft_quota *priv)
{
	return priv->flags & NFT_QUOTA_F_INV;
}

static inline void nft_quota_do_eval(struct nft_quota *priv,
				     struct nft_regs *regs,
				     const struct nft_pktinfo *pkt)
{
	if (nft_overquota(priv, pkt->skb) ^ nft_quota_invert(priv))
		regs->verdict.code = NFT_BREAK;
}

static const struct nla_policy nft_quota_policy[NFTA_QUOTA_MAX + 1] = {
	[NFTA_QUOTA_BYTES]	= { .type = NLA_U64 },
	[NFTA_QUOTA_FLAGS]	= { .type = NLA_U32 },
	[NFTA_QUOTA_CONSUMED]	= { .type = NLA_U64 },
};

#define NFT_QUOTA_DEPLETED_BIT	1	/* From NFT_QUOTA_F_DEPLETED. */

static void nft_quota_obj_eval(struct nft_object *obj,
			       struct nft_regs *regs,
			       const struct nft_pktinfo *pkt)
{
	struct nft_quota *priv = nft_obj_data(obj);
	bool overquota;

	overquota = nft_overquota(priv, pkt->skb);
	if (overquota ^ nft_quota_invert(priv))
		regs->verdict.code = NFT_BREAK;

	if (overquota &&
	    !test_and_set_bit(NFT_QUOTA_DEPLETED_BIT, &priv->flags))
		nft_obj_notify(nft_net(pkt), obj->table, obj, 0, 0,
			       NFT_MSG_NEWOBJ, nft_pf(pkt), 0, GFP_ATOMIC);
}

static int nft_quota_do_init(const struct nlattr * const tb[],
			     struct nft_quota *priv)
{
	unsigned long flags = 0;
	u64 quota, consumed = 0;

	if (!tb[NFTA_QUOTA_BYTES])
		return -EINVAL;

	quota = be64_to_cpu(nla_get_be64(tb[NFTA_QUOTA_BYTES]));
	if (quota > S64_MAX)
		return -EOVERFLOW;

	if (tb[NFTA_QUOTA_CONSUMED]) {
		consumed = be64_to_cpu(nla_get_be64(tb[NFTA_QUOTA_CONSUMED]));
		if (consumed > quota)
			return -EINVAL;
	}

	if (tb[NFTA_QUOTA_FLAGS]) {
		flags = ntohl(nla_get_be32(tb[NFTA_QUOTA_FLAGS]));
		if (flags & ~NFT_QUOTA_F_INV)
			return -EINVAL;
		if (flags & NFT_QUOTA_F_DEPLETED)
			return -EOPNOTSUPP;
	}

	priv->quota = quota;
	priv->flags = flags;
	atomic64_set(&priv->consumed, consumed);

	return 0;
}

static int nft_quota_obj_init(const struct nlattr * const tb[],
			      struct nft_object *obj)
{
	struct nft_quota *priv = nft_obj_data(obj);

	return nft_quota_do_init(tb, priv);
}

static int nft_quota_do_dump(struct sk_buff *skb, struct nft_quota *priv,
			     bool reset)
{
	u32 flags = priv->flags;
	u64 consumed;

	if (reset) {
		consumed = atomic64_xchg(&priv->consumed, 0);
		if (test_and_clear_bit(NFT_QUOTA_DEPLETED_BIT, &priv->flags))
			flags |= NFT_QUOTA_F_DEPLETED;
	} else {
		consumed = atomic64_read(&priv->consumed);
	}

	/* Since we inconditionally increment consumed quota for each packet
	 * that we see, don't go over the quota boundary in what we send to
	 * userspace.
	 */
	if (consumed > priv->quota)
		consumed = priv->quota;

	if (nla_put_be64(skb, NFTA_QUOTA_BYTES, cpu_to_be64(priv->quota),
			 NFTA_QUOTA_PAD) ||
	    nla_put_be64(skb, NFTA_QUOTA_CONSUMED, cpu_to_be64(consumed),
			 NFTA_QUOTA_PAD) ||
	    nla_put_be32(skb, NFTA_QUOTA_FLAGS, htonl(flags)))
		goto nla_put_failure;
	return 0;

nla_put_failure:
	return -1;
}

static int nft_quota_obj_dump(struct sk_buff *skb, struct nft_object *obj,
			      bool reset)
{
	struct nft_quota *priv = nft_obj_data(obj);

	return nft_quota_do_dump(skb, priv, reset);
}

static struct nft_object_type nft_quota_obj __read_mostly = {
	.type		= NFT_OBJECT_QUOTA,
	.size		= sizeof(struct nft_quota),
	.maxattr	= NFTA_QUOTA_MAX,
	.policy		= nft_quota_policy,
	.init		= nft_quota_obj_init,
	.eval		= nft_quota_obj_eval,
	.dump		= nft_quota_obj_dump,
	.owner		= THIS_MODULE,
};

static void nft_quota_eval(const struct nft_expr *expr,
			   struct nft_regs *regs,
			   const struct nft_pktinfo *pkt)
{
	struct nft_quota *priv = nft_expr_priv(expr);

	nft_quota_do_eval(priv, regs, pkt);
}

static int nft_quota_init(const struct nft_ctx *ctx,
			  const struct nft_expr *expr,
			  const struct nlattr * const tb[])
{
	struct nft_quota *priv = nft_expr_priv(expr);

	return nft_quota_do_init(tb, priv);
}

static int nft_quota_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
	struct nft_quota *priv = nft_expr_priv(expr);

	return nft_quota_do_dump(skb, priv, false);
}

static struct nft_expr_type nft_quota_type;
static const struct nft_expr_ops nft_quota_ops = {
	.type		= &nft_quota_type,
	.size		= NFT_EXPR_SIZE(sizeof(struct nft_quota)),
	.eval		= nft_quota_eval,
	.init		= nft_quota_init,
	.dump		= nft_quota_dump,
};

static struct nft_expr_type nft_quota_type __read_mostly = {
	.name		= "quota",
	.ops		= &nft_quota_ops,
	.policy		= nft_quota_policy,
	.maxattr	= NFTA_QUOTA_MAX,
	.flags		= NFT_EXPR_STATEFUL,
	.owner		= THIS_MODULE,
};

static int __init nft_quota_module_init(void)
{
	int err;

	err = nft_register_obj(&nft_quota_obj);
	if (err < 0)
		return err;

	err = nft_register_expr(&nft_quota_type);
	if (err < 0)
		goto err1;

	return 0;
err1:
	nft_unregister_obj(&nft_quota_obj);
	return err;
}

static void __exit nft_quota_module_exit(void)
{
	nft_unregister_expr(&nft_quota_type);
	nft_unregister_obj(&nft_quota_obj);
}

module_init(nft_quota_module_init);
module_exit(nft_quota_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Pablo Neira Ayuso <pablo@netfilter.org>");
MODULE_ALIAS_NFT_EXPR("quota");
MODULE_ALIAS_NFT_OBJ(NFT_OBJECT_QUOTA);
