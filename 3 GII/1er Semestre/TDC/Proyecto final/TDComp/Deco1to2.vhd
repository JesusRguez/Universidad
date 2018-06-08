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

entity Deco1to2 is
    Port ( Input : in  STD_LOGIC_VECTOR (9 downto 0);
           Enable : in  STD_LOGIC;
           OutputA : out  STD_LOGIC_VECTOR (3 downto 0);
			  OutputB : out  STD_LOGIC_VECTOR (9 downto 0));
end Deco1to2;

architecture Behavioral of Deco1to2 is

begin

	process(Input,Enable)
	begin
		if Enable='0' then
			OutputA<="0000";
			OutputB<=Input;
		else--Cuando enable vale 1, cogemos el dato inmediato al banco
			OutputB<="0000000000";
			OutputA<=Input(3 downto 0);
		end if;
	end process;

end Behavioral;

