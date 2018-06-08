----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:37:15 01/22/2018 
-- Design Name: 
-- Module Name:    Deco1to2 - Behavioral 
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
    Port ( Input : in  STD_LOGIC_VECTOR (3 downto 0);
           Enable : in  STD_LOGIC_VECTOR (1 downto 0);
           OutputA : out  STD_LOGIC_VECTOR (3 downto 0);--RAM
			  OutputB : out  STD_LOGIC_VECTOR (2 downto 0);--Banco
			  OutputC : out  STD_LOGIC_VECTOR (3 downto 0));--Inmediato
end Deco2to4;

architecture Behavioral of Deco2to4 is

begin

	process(Input,Enable)
	begin
		case Enable is
				when "00"=>
					OutputA<=Input;
					OutputB<="000";
					OutputC<="0000";
				when "01"=>
					OutputA<="0000";
					OutputB<=Input(2 downto 0);
					OutputC<="0000";
				when "10"=>
					OutputA<="0000";
					OutputB<="000";
					OutputC<=Input;
				when others =>
					OutputA<="0000";
					OutputB<="000";
					OutputC<="0000";
			end case;
	end process;

end Behavioral;

