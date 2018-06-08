/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xa0883be4 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "C:/Users/Jesus/Xilinx/TDComp/Deco3to8.vhd";



static void work_a_3383518998_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    unsigned char t4;
    char *t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    int t12;
    int t13;
    int t14;
    int t16;
    char *t17;
    int t19;
    char *t20;
    int t22;
    char *t23;
    int t25;
    char *t26;
    int t28;
    char *t29;
    char *t31;
    char *t32;
    char *t33;
    char *t34;
    char *t35;

LAB0:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(47, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4536);
    t12 = xsi_mem_cmp(t1, t2, 3U);
    if (t12 == 1)
        goto LAB8;

LAB17:    t7 = (t0 + 4539);
    t13 = xsi_mem_cmp(t7, t2, 3U);
    if (t13 == 1)
        goto LAB9;

LAB18:    t9 = (t0 + 4542);
    t14 = xsi_mem_cmp(t9, t2, 3U);
    if (t14 == 1)
        goto LAB10;

LAB19:    t11 = (t0 + 4545);
    t16 = xsi_mem_cmp(t11, t2, 3U);
    if (t16 == 1)
        goto LAB11;

LAB20:    t17 = (t0 + 4548);
    t19 = xsi_mem_cmp(t17, t2, 3U);
    if (t19 == 1)
        goto LAB12;

LAB21:    t20 = (t0 + 4551);
    t22 = xsi_mem_cmp(t20, t2, 3U);
    if (t22 == 1)
        goto LAB13;

LAB22:    t23 = (t0 + 4554);
    t25 = xsi_mem_cmp(t23, t2, 3U);
    if (t25 == 1)
        goto LAB14;

LAB23:    t26 = (t0 + 4557);
    t28 = xsi_mem_cmp(t26, t2, 3U);
    if (t28 == 1)
        goto LAB15;

LAB24:
LAB16:    xsi_set_current_line(56, ng0);
    t1 = (t0 + 4624);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);

LAB7:
LAB3:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(45, ng0);
    t1 = (t0 + 4528);
    t6 = (8U != 8U);
    if (t6 == 1)
        goto LAB5;

LAB6:    t7 = (t0 + 2912);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_delta(t7, 0U, 8U, 0LL);
    goto LAB3;

LAB5:    xsi_size_not_matching(8U, 8U, 0);
    goto LAB6;

LAB8:    xsi_set_current_line(48, ng0);
    t29 = (t0 + 4560);
    t31 = (t0 + 2912);
    t32 = (t31 + 56U);
    t33 = *((char **)t32);
    t34 = (t33 + 56U);
    t35 = *((char **)t34);
    memcpy(t35, t29, 8U);
    xsi_driver_first_trans_fast_port(t31);
    goto LAB7;

LAB9:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 4568);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB10:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 4576);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB11:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 4584);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB12:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 4592);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB13:    xsi_set_current_line(53, ng0);
    t1 = (t0 + 4600);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB14:    xsi_set_current_line(54, ng0);
    t1 = (t0 + 4608);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB15:    xsi_set_current_line(55, ng0);
    t1 = (t0 + 4616);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 8U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB25:;
}


extern void work_a_3383518998_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3383518998_3212880686_p_0};
	xsi_register_didat("work_a_3383518998_3212880686", "isim/TOP_tb_isim_beh.exe.sim/work/a_3383518998_3212880686.didat");
	xsi_register_executes(pe);
}
