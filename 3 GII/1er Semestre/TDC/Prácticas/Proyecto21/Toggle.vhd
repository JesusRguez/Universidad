----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:14:57 11/08/2017 
-- Design Name: 
-- Module Name:    Toggle - Behavioral 
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

entity Toggle is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           ENABLE : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end Toggle;

architecture Behavioral of Toggle is

signal Q_signal: std_logic;

begin
	process(CLK, RESET)
	begin
		if RESET='1' then
			Q_signal<='0';
		elsif rising_edge(CLK) then
			if ENABLE='1' then
				Q_signal<=not Q_signal;
			end if;
		end if;
	end process;
	
	Q<=Q_signal;
	
end Behavioral;

