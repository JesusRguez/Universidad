----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:26:08 10/18/2017 
-- Design Name: 
-- Module Name:    Disp7Seg - Behavioral 
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

entity Disp7Seg is
    Port ( Hex : in  STD_LOGIC_VECTOR (3 downto 0);
           Select_Disp : in  STD_LOGIC_VECTOR (1 downto 0);
           Seg : out  STD_LOGIC_VECTOR (6 downto 0);
			  -- seg6=a.....seg0=g
           Anode : out  STD_LOGIC_VECTOR (3 downto 0));
end Disp7Seg;

architecture Behavioral of Disp7Seg is

begin
	process(Hex, Select_disp)
		begin
		case Select_disp is
			when "00"=>Anode<="1110";
			when "01"=>Anode<="1101";
			when "10"=>Anode<="1011";
			when "11"=>Anode<="0111";
			when others =>Anode<="1111";
		end case;
		
		case Hex is
			when "0000"=>Seg<="0000001";
			when "0001"=>Seg<="1001111";
			when "0010"=>Seg<="0010010";
			when "0011"=>Seg<="0000110";
			when "0100"=>Seg<="1001100";
			when "0101"=>Seg<="0100100";
			when "0110"=>Seg<="0100000";
			when "0111"=>Seg<="0001111";
			when "1000"=>Seg<="0000000";
			when "1001"=>Seg<="0000100";
			when "1010"=>Seg<="0001000";
			when "1011"=>Seg<="1100000";
			when "1100"=>Seg<="1110010";
			when "1101"=>Seg<="1000010";
			when "1110"=>Seg<="0110000";
			when "1111"=>Seg<="0111000";
			when others =>Seg<="1111111";
		end case;
	end process;
end Behavioral;

