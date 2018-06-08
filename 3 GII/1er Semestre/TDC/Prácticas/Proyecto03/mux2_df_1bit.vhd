----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:47:40 10/11/2017 
-- Design Name: 
-- Module Name:    mux2_df_1bit - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity mux2_df_1bit is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Sel : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end mux2_df_1bit;

architecture Dataflow of mux2_df_1bit is
-- Declaración de señales
signal signal_1, signal_2 : std_logic;
begin
	--Y <= (A and (not Sel)) or (B and Sel); --Descripción del MUX mediante Dataflow
	signal_1<=A and (not Sel);
	signal_2<=B and Sel;
	Y <= signal_1 or signal_2;
end Dataflow;

