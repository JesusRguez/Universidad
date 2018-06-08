----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:30:11 01/21/2018 
-- Design Name: 
-- Module Name:    Deco3to8 - Behavioral 
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

entity Deco3to8 is
    Port ( Input : in  STD_LOGIC_VECTOR (2 downto 0);
           Enable : in  STD_LOGIC;
           Output : out  STD_LOGIC_VECTOR (7 downto 0));
end Deco3to8;

architecture Behavioral of Deco3to8 is

begin

	process(Input,Enable)
	begin
		if Enable='0' then
			Output(7 downto 0)<="00000000";
		else
			case Input is
				when "000"=>Output<="00000001";
				when "001"=>Output<="00000010";
				when "010"=>Output<="00000100";
				when "011"=>Output<="00001000";
				when "100"=>Output<="00010000";
				when "101"=>Output<="00100000";
				when "110"=>Output<="01000000";
				when "111"=>Output<="10000000";
				when others =>Output<="00000000";
			end case;
		end if;
	end process;

end Behavioral;

