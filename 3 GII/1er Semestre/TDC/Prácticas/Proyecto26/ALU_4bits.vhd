----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:11:52 10/25/2017 
-- Design Name: 
-- Module Name:    ALU_4bits - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU_4bits is
    Port ( OPE_A : in  STD_LOGIC_VECTOR (3 downto 0);
           OPE_B : in  STD_LOGIC_VECTOR (3 downto 0);
           SEL_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           Sal_ALU : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
			  
end ALU_4bits;



architecture Behavioral of ALU_4bits is

signal Resultado : std_logic_vector(3 downto 0);

begin
	process(OPE_A, OPE_B, SEL_ALU)
		begin
			case SEL_ALU is
				when "00"=>Resultado<=OPE_A;
				when "01"=>Resultado<="0000";
				when "10"=>Resultado<=std_logic_vector(signed(OPE_A)+signed(OPE_B));
				when "11"=>Resultado<=std_logic_vector(signed(OPE_A)-signed(OPE_B));
				when others =>Resultado<="0000";
			end case;
			Sal_ALU<=Resultado;
			case Resultado is
				when "0000"=>SalFZ<='1';
				when others=>SalFZ<='0';
			end case;
	end process;
end Behavioral;