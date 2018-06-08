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

char *IEEE_P_1242562249;
char *IEEE_P_2592010699;
char *STD_STANDARD;


int main(int argc, char **argv)
{
    xsi_init_design(argc, argv);
    xsi_register_info(&xsi_info);

    xsi_register_min_prec_unit(-12);
    ieee_p_2592010699_init();
    work_a_2226869184_3212880686_init();
    work_a_2096391741_3212880686_init();
    ieee_p_1242562249_init();
    work_a_1429443482_3212880686_init();
    work_a_0659509283_3212880686_init();
    work_a_4199442440_3212880686_init();
    work_a_1386257851_3212880686_init();
    work_a_1690425201_3212880686_init();
    work_a_1788161657_3212880686_init();
    work_a_1188518911_3212880686_init();
    work_a_2964943639_3212880686_init();
    work_a_0832606739_3212880686_init();
    work_a_3020046699_3212880686_init();
    work_a_2399776393_3212880686_init();
    work_a_3023951981_3212880686_init();
    work_a_3383518998_3212880686_init();
    work_a_2638288158_3212880686_init();
    work_a_0661437355_3212880686_init();
    work_a_3127459671_3212880686_init();
    work_a_1152930923_3212880686_init();
    work_a_1283225550_3212880686_init();
    work_a_3045778815_3212880686_init();
    work_a_4064625254_3212880686_init();
    work_a_3915952611_3212880686_init();
    work_a_1993781925_3212880686_init();
    work_a_1335952598_3212880686_init();
    work_a_3115858369_2372691052_init();


    xsi_register_tops("work_a_3115858369_2372691052");

    IEEE_P_1242562249 = xsi_get_engine_memory("ieee_p_1242562249");
    IEEE_P_2592010699 = xsi_get_engine_memory("ieee_p_2592010699");
    xsi_register_ieee_std_logic_1164(IEEE_P_2592010699);
    STD_STANDARD = xsi_get_engine_memory("std_standard");

    return xsi_run_simulation(argc, argv);

}
