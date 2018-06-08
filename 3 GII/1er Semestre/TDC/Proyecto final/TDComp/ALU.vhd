----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:40:31 01/21/2018 
-- Design Name: 
-- Module Name:    ALU - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ALU is
    Port ( OPE_A : in  STD_LOGIC_VECTOR (3 downto 0);
           OPE_B : in  STD_LOGIC_VECTOR (3 downto 0);
           COP : in  STD_LOGIC_VECTOR (2 downto 0);
           SalALU : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
end ALU;

architecture Behavioral of ALU is

signal Resultado : std_logic_vector(3 downto 0);

begin
	process(OPE_A, OPE_B, COP)
		begin
			case COP is
				when "000"=>Resultado<=OPE_A;
				when "001"=>Resultado<=OPE_B;
				when "010"=>Resultado<=std_logic_vector(signed(OPE_A)+signed(OPE_B));
				when "011"=>Resultado<=std_logic_vector(signed(OPE_A)-signed(OPE_B));
				when "100"=>Resultado<=std_logic_vector(signed(OPE_A)+signed(OPE_B));
				when "101"=>Resultado<=std_logic_vector(signed(OPE_B)-signed(OPE_A));
				when "110"=>Resultado<="0000";
				when others =>Resultado<="0000";
			end case;
			SalALU<=Resultado;
			case Resultado is
				when "0000"=>SalFZ<='1';
				when others=>SalFZ<='0';
			end case;
	end process;

end Behavioral;

