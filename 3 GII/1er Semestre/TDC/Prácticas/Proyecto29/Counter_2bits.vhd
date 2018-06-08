----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:21:42 11/15/2017 
-- Design Name: 
-- Module Name:    Counter_2bits - Behavioral 
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
use IEEE.numeric_std.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Counter_2bits is
    Port ( ENABLE : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (1 downto 0));
end Counter_2bits;

architecture Behavioral of Counter_2bits is
	signal CUENTA: unsigned (1 downto 0);

begin
	process(CLK, RESET)
	begin
		if RESET = '1' then
			CUENTA<="00";
			elsif rising_edge(CLK) then
				if ENABLE='1' then
					CUENTA <= CUENTA +1;
				end if;
			end if;
	end process;
	
	Q<=STD_LOGIC_VECTOR(CUENTA);
end Behavioral;

