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

#include "xsi.h"

struct XSI_INFO xsi_info;

char *STD_STANDARD;
char *IEEE_P_2592010699;
char *IEEE_P_1242562249;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    work_a_0738021914_3212880686_init();
    ieee_p_1242562249_init();
    work_a_2078128788_3212880686_init();
    work_a_0659509283_3212880686_init();
    work_a_1377546970_3212880686_init();
    work_a_3020046699_3212880686_init();
    work_a_2980731121_3212880686_init();
    work_a_2854155025_3212880686_init();
    work_a_2960840703_3212880686_init();
    work_a_1690425201_3212880686_init();
    work_a_4199442440_3212880686_init();
    work_a_1793609385_3212880686_init();
    work_a_1513903739_3212880686_init();
    work_a_0675321282_3212880686_init();
    work_a_2268950096_3212880686_init();
    work_a_1912316773_3212880686_init();
    work_a_3277914147_3212880686_init();
    work_a_0232986857_2372691052_init();


    xsi_register_tops("work_a_0232986857_2372691052");

    STD_STANDARD = xsi_get_engine_memory("std_standard");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");

    return xsi_run_simulation(argc, argv);

}
