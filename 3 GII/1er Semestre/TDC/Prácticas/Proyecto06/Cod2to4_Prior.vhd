----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:16:25 10/13/2017 
-- Design Name: 
-- Module Name:    Cod2to4_Prior - Behavioral 
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

entity Cod2to4_Prior is
    Port ( I : in  STD_LOGIC_VECTOR (3 downto 0);
           Enable : in  STD_LOGIC;
           S : out  STD_LOGIC_VECTOR (1 downto 0));
end Cod2to4_Prior;

architecture Behavioral of Cod2to4_Prior is

begin
process(I, Enable)
begin
	if Enable='0' then
		S<="ZZ";
	else
		case I is
			when "1000"=>S<="11";
			when "0100"=>S<="10";
			when "0010"=>S<="01";
			when "0001"=>S<="00";
			when others =>S<="11";
		end case;
	end if;
end process;
end Behavioral;

