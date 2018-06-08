----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:44:19 11/08/2017 
-- Design Name: 
-- Module Name:    RisingEdge - Behavioral 
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

entity RisingEdge is
    Port ( RESET : in  STD_LOGIC;
           PUSH : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Pulse : out  STD_LOGIC);
end RisingEdge;

architecture Behavioral of RisingEdge is

signal RegisteredPush: std_logic;
signal PreviousPush: std_logic;

begin
	SincPush:process(CLK, RESET)
		begin
			if RESET='1' then
				RegisteredPush<='0';
			elsif rising_edge(CLK) then
				RegisteredPush<=PUSH;
			end if;
		end process;
	
	StorePrevPush:process(CLK, RESET)
		begin 
			if RESET='1' then
				PreviousPush<='0';
			elsif rising_edge(CLK) then
				PreviousPush<=RegisteredPush;
			end if;
		end process;
	
	Pulse<='1' when PreviousPush='0' and RegisteredPush='1'
		else '0';
		
end Behavioral;

