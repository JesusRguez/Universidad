--------------------------------------------------------------------------------
-- Copyright (c) 1995-2012 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.28xd
--  \   \         Application: netgen
--  /   /         Filename: Mux_Disp_LED_synthesis.vhd
-- /___/   /\     Timestamp: Wed Oct 18 12:48:36 2017
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm Mux_Disp_LED -w -dir netgen/synthesis -ofmt vhdl -sim Mux_Disp_LED.ngc Mux_Disp_LED_synthesis.vhd 
-- Device	: xc3s100e-4-cp132
-- Input file	: Mux_Disp_LED.ngc
-- Output file	: C:\Users\Jesus\Xilinx\Proyecto09\netgen\synthesis\Mux_Disp_LED_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: Mux_Disp_LED
-- Xilinx	: C:\Xilinx\14.2\ISE_DS\ISE\
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Command Line Tools User Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity Mux_Disp_LED is
  port (
    Sel : in STD_LOGIC := 'X'; 
    Anode : out STD_LOGIC_VECTOR ( 3 downto 0 ); 
    Seg : out STD_LOGIC_VECTOR ( 6 downto 0 ); 
    LED : out STD_LOGIC_VECTOR ( 3 downto 0 ); 
    A : in STD_LOGIC_VECTOR ( 3 downto 0 ); 
    B : in STD_LOGIC_VECTOR ( 3 downto 0 ) 
  );
end Mux_Disp_LED;

architecture Structure of Mux_Disp_LED is
  signal A_0_IBUF_4 : STD_LOGIC; 
  signal A_1_IBUF_5 : STD_LOGIC; 
  signal A_2_IBUF_6 : STD_LOGIC; 
  signal A_3_IBUF_7 : STD_LOGIC; 
  signal B_0_IBUF_16 : STD_LOGIC; 
  signal B_1_IBUF_17 : STD_LOGIC; 
  signal B_2_IBUF_18 : STD_LOGIC; 
  signal B_3_IBUF_19 : STD_LOGIC; 
  signal LED_0_OBUF_24 : STD_LOGIC; 
  signal LED_1_OBUF_25 : STD_LOGIC; 
  signal LED_2_OBUF_26 : STD_LOGIC; 
  signal LED_3_OBUF_27 : STD_LOGIC; 
  signal N0 : STD_LOGIC; 
  signal N1 : STD_LOGIC; 
  signal Seg_0_OBUF_37 : STD_LOGIC; 
  signal Seg_1_OBUF_38 : STD_LOGIC; 
  signal Seg_2_OBUF_39 : STD_LOGIC; 
  signal Seg_3_OBUF_40 : STD_LOGIC; 
  signal Seg_4_OBUF_41 : STD_LOGIC; 
  signal Seg_5_OBUF_42 : STD_LOGIC; 
  signal Seg_6_OBUF_43 : STD_LOGIC; 
  signal Sel_IBUF_45 : STD_LOGIC; 
begin
  XST_GND : GND
    port map (
      G => N0
    );
  XST_VCC : VCC
    port map (
      P => N1
    );
  Inst_Mux2_4bits_Z_3_1 : LUT3
    generic map(
      INIT => X"D8"
    )
    port map (
      I0 => Sel_IBUF_45,
      I1 => B_3_IBUF_19,
      I2 => A_3_IBUF_7,
      O => LED_3_OBUF_27
    );
  Inst_Mux2_4bits_Z_2_1 : LUT3
    generic map(
      INIT => X"D8"
    )
    port map (
      I0 => Sel_IBUF_45,
      I1 => B_2_IBUF_18,
      I2 => A_2_IBUF_6,
      O => LED_2_OBUF_26
    );
  Inst_Mux2_4bits_Z_1_1 : LUT3
    generic map(
      INIT => X"D8"
    )
    port map (
      I0 => Sel_IBUF_45,
      I1 => B_1_IBUF_17,
      I2 => A_1_IBUF_5,
      O => LED_1_OBUF_25
    );
  Inst_Mux2_4bits_Z_0_1 : LUT3
    generic map(
      INIT => X"D8"
    )
    port map (
      I0 => Sel_IBUF_45,
      I1 => B_0_IBUF_16,
      I2 => A_0_IBUF_4,
      O => LED_0_OBUF_24
    );
  Inst_Disp7Seg_Mrom_Seg12 : LUT4
    generic map(
      INIT => X"4101"
    )
    port map (
      I0 => LED_3_OBUF_27,
      I1 => LED_1_OBUF_25,
      I2 => LED_2_OBUF_26,
      I3 => LED_0_OBUF_24,
      O => Seg_0_OBUF_37
    );
  Inst_Disp7Seg_Mrom_Seg21 : LUT4
    generic map(
      INIT => X"454C"
    )
    port map (
      I0 => LED_3_OBUF_27,
      I1 => LED_0_OBUF_24,
      I2 => LED_1_OBUF_25,
      I3 => LED_2_OBUF_26,
      O => Seg_2_OBUF_39
    );
  Inst_Disp7Seg_Mrom_Seg41 : LUT4
    generic map(
      INIT => X"80C2"
    )
    port map (
      I0 => LED_1_OBUF_25,
      I1 => LED_3_OBUF_27,
      I2 => LED_2_OBUF_26,
      I3 => LED_0_OBUF_24,
      O => Seg_4_OBUF_41
    );
  Inst_Disp7Seg_Mrom_Seg111 : LUT4
    generic map(
      INIT => X"6432"
    )
    port map (
      I0 => LED_1_OBUF_25,
      I1 => LED_3_OBUF_27,
      I2 => LED_0_OBUF_24,
      I3 => LED_2_OBUF_26,
      O => Seg_1_OBUF_38
    );
  Inst_Disp7Seg_Mrom_Seg61 : LUT4
    generic map(
      INIT => X"2C06"
    )
    port map (
      I0 => LED_0_OBUF_24,
      I1 => LED_2_OBUF_26,
      I2 => LED_1_OBUF_25,
      I3 => LED_3_OBUF_27,
      O => Seg_6_OBUF_43
    );
  Inst_Disp7Seg_Mrom_Seg51 : LUT4
    generic map(
      INIT => X"E448"
    )
    port map (
      I0 => LED_0_OBUF_24,
      I1 => LED_2_OBUF_26,
      I2 => LED_1_OBUF_25,
      I3 => LED_3_OBUF_27,
      O => Seg_5_OBUF_42
    );
  Inst_Disp7Seg_Mrom_Seg31 : LUT4
    generic map(
      INIT => X"A118"
    )
    port map (
      I0 => LED_1_OBUF_25,
      I1 => LED_3_OBUF_27,
      I2 => LED_0_OBUF_24,
      I3 => LED_2_OBUF_26,
      O => Seg_3_OBUF_40
    );
  Sel_IBUF : IBUF
    port map (
      I => Sel,
      O => Sel_IBUF_45
    );
  A_3_IBUF : IBUF
    port map (
      I => A(3),
      O => A_3_IBUF_7
    );
  A_2_IBUF : IBUF
    port map (
      I => A(2),
      O => A_2_IBUF_6
    );
  A_1_IBUF : IBUF
    port map (
      I => A(1),
      O => A_1_IBUF_5
    );
  A_0_IBUF : IBUF
    port map (
      I => A(0),
      O => A_0_IBUF_4
    );
  B_3_IBUF : IBUF
    port map (
      I => B(3),
      O => B_3_IBUF_19
    );
  B_2_IBUF : IBUF
    port map (
      I => B(2),
      O => B_2_IBUF_18
    );
  B_1_IBUF : IBUF
    port map (
      I => B(1),
      O => B_1_IBUF_17
    );
  B_0_IBUF : IBUF
    port map (
      I => B(0),
      O => B_0_IBUF_16
    );
  Anode_3_OBUF : OBUF
    port map (
      I => N1,
      O => Anode(3)
    );
  Anode_2_OBUF : OBUF
    port map (
      I => N1,
      O => Anode(2)
    );
  Anode_1_OBUF : OBUF
    port map (
      I => N1,
      O => Anode(1)
    );
  Anode_0_OBUF : OBUF
    port map (
      I => N0,
      O => Anode(0)
    );
  Seg_6_OBUF : OBUF
    port map (
      I => Seg_6_OBUF_43,
      O => Seg(6)
    );
  Seg_5_OBUF : OBUF
    port map (
      I => Seg_5_OBUF_42,
      O => Seg(5)
    );
  Seg_4_OBUF : OBUF
    port map (
      I => Seg_4_OBUF_41,
      O => Seg(4)
    );
  Seg_3_OBUF : OBUF
    port map (
      I => Seg_3_OBUF_40,
      O => Seg(3)
    );
  Seg_2_OBUF : OBUF
    port map (
      I => Seg_2_OBUF_39,
      O => Seg(2)
    );
  Seg_1_OBUF : OBUF
    port map (
      I => Seg_1_OBUF_38,
      O => Seg(1)
    );
  Seg_0_OBUF : OBUF
    port map (
      I => Seg_0_OBUF_37,
      O => Seg(0)
    );
  LED_3_OBUF : OBUF
    port map (
      I => LED_3_OBUF_27,
      O => LED(3)
    );
  LED_2_OBUF : OBUF
    port map (
      I => LED_2_OBUF_26,
      O => LED(2)
    );
  LED_1_OBUF : OBUF
    port map (
      I => LED_1_OBUF_25,
      O => LED(1)
    );
  LED_0_OBUF : OBUF
    port map (
      I => LED_0_OBUF_24,
      O => LED(0)
    );

end Structure;

