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
static const char *ng0 = "C:/Users/Jesus/Xilinx/Proyecto05/Deco2to4.vhd";



static void work_a_3023951981_3212880686_p_0(char *t0)
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
    char *t19;
    char *t20;
    char *t21;
    char *t22;
    char *t23;

LAB0:    xsi_set_current_line(43, ng0);
    t1 = (t0 + 1192U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t4 = (t3 == (unsigned char)2);
    if (t4 != 0)
        goto LAB2;

LAB4:    xsi_set_current_line(46, ng0);
    t1 = (t0 + 1032U);
    t2 = *((char **)t1);
    t1 = (t0 + 4531);
    t12 = xsi_mem_cmp(t1, t2, 2U);
    if (t12 == 1)
        goto LAB8;

LAB13:    t7 = (t0 + 4533);
    t13 = xsi_mem_cmp(t7, t2, 2U);
    if (t13 == 1)
        goto LAB9;

LAB14:    t9 = (t0 + 4535);
    t14 = xsi_mem_cmp(t9, t2, 2U);
    if (t14 == 1)
        goto LAB10;

LAB15:    t11 = (t0 + 4537);
    t16 = xsi_mem_cmp(t11, t2, 2U);
    if (t16 == 1)
        goto LAB11;

LAB16:
LAB12:    xsi_set_current_line(51, ng0);
    t1 = (t0 + 4555);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);

LAB7:
LAB3:    t1 = (t0 + 2832);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(44, ng0);
    t1 = (t0 + 4527);
    t6 = (4U != 4U);
    if (t6 == 1)
        goto LAB5;

LAB6:    t7 = (t0 + 2912);
    t8 = (t7 + 56U);
    t9 = *((char **)t8);
    t10 = (t9 + 56U);
    t11 = *((char **)t10);
    memcpy(t11, t1, 4U);
    xsi_driver_first_trans_delta(t7, 0U, 4U, 0LL);
    goto LAB3;

LAB5:    xsi_size_not_matching(4U, 4U, 0);
    goto LAB6;

LAB8:    xsi_set_current_line(47, ng0);
    t17 = (t0 + 4539);
    t19 = (t0 + 2912);
    t20 = (t19 + 56U);
    t21 = *((char **)t20);
    t22 = (t21 + 56U);
    t23 = *((char **)t22);
    memcpy(t23, t17, 4U);
    xsi_driver_first_trans_fast_port(t19);
    goto LAB7;

LAB9:    xsi_set_current_line(48, ng0);
    t1 = (t0 + 4543);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB10:    xsi_set_current_line(49, ng0);
    t1 = (t0 + 4547);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB11:    xsi_set_current_line(50, ng0);
    t1 = (t0 + 4551);
    t5 = (t0 + 2912);
    t7 = (t5 + 56U);
    t8 = *((char **)t7);
    t9 = (t8 + 56U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast_port(t5);
    goto LAB7;

LAB17:;
}


extern void work_a_3023951981_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3023951981_3212880686_p_0};
	xsi_register_didat("work_a_3023951981_3212880686", "isim/Deco2to4_tb_isim_beh.exe.sim/work/a_3023951981_3212880686.didat");
	xsi_register_executes(pe);
}
