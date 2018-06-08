----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:56:24 01/21/2018 
-- Design Name: 
-- Module Name:    Mux8_4bits - Behavioral 
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

entity Mux8_4bits is
    Port ( R1 : in  STD_LOGIC_VECTOR (3 downto 0);
           R2 : in  STD_LOGIC_VECTOR (3 downto 0);
           R3 : in  STD_LOGIC_VECTOR (3 downto 0);
           R4 : in  STD_LOGIC_VECTOR (3 downto 0);
           R5 : in  STD_LOGIC_VECTOR (3 downto 0);
           R6 : in  STD_LOGIC_VECTOR (3 downto 0);
           R7 : in  STD_LOGIC_VECTOR (3 downto 0);
           R8 : in  STD_LOGIC_VECTOR (3 downto 0);
           SelReg : in  STD_LOGIC_VECTOR (2 downto 0);
           Z : out  STD_LOGIC_VECTOR (3 downto 0));
end Mux8_4bits;

architecture Behavioral of Mux8_4bits is

begin

	process(R1,R2,R3,R4,R5,R6,R7,R8,SelReg)
		begin
			case SelReg is
				when "000"=>Z<=R1;
				when "001"=>Z<=R2;
				when "010"=>Z<=R3;
				when "011"=>Z<=R4;
				when "100"=>Z<=R5;
				when "101"=>Z<=R6;
				when "110"=>Z<=R7;
				when "111"=>Z<=R8;
				when others =>Z<="0000";
			end case;
	end process;

end Behavioral;

