----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:49:01 10/13/2017 
-- Design Name: 
-- Module Name:    Deco2to4 - Behavioral 
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

entity Deco2to4 is
    Port ( I : in  STD_LOGIC_VECTOR (1 downto 0);
           Enable : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (3 downto 0));
end Deco2to4;

architecture Behavioral of Deco2to4 is

begin
	process(I,Enable)
	begin
		if Enable='0' then
			S(3 downto 0)<="0000";
		else
			case I is
				when "00"=>S<="0001";
				when "01"=>S<="0010";
				when "10"=>S<="0100";
				when "11"=>S<="1000";
				when others =>S<="1111";
			end case;
		end if;
	end process;
end Behavioral;

