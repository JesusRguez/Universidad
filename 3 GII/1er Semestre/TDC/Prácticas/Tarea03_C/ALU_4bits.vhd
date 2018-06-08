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
	Generic (N: INTEGER:=7);
    Port ( OPE_A : in  STD_LOGIC_VECTOR (N downto 0);
           OPE_B : in  STD_LOGIC_VECTOR (N downto 0);
           SEL_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           Sal_ALU : out  STD_LOGIC_VECTOR (N downto 0);
           SalFZ : out  STD_LOGIC);
			  
end ALU_4bits;



architecture Behavioral of ALU_4bits is

signal Resultado : std_logic_vector(N downto 0);

constant ceros: std_logic_vector (N downto 0):= (others=>'0');

begin
	process(OPE_A, OPE_B, SEL_ALU)
		begin
			case SEL_ALU is --Case to select the result in the signal Resultado
				when "00"=>Resultado<=OPE_A;
				when "01"=>Resultado<=(others =>'0');
				when "10"=>Resultado<=std_logic_vector(signed(OPE_A)+signed(OPE_B));
				when "11"=>Resultado<=std_logic_vector(signed(OPE_A)-signed(OPE_B));
				when others =>Resultado<=(others =>'0');
			end case;
			
			Sal_ALU<=Resultado; 
			
			if Resultado=ceros then --If sentence to compare the result with the signal ceros
					SalFZ<='1';
				else
					SalFZ<='0';
				end if;
			
	end process;
end Behavioral;