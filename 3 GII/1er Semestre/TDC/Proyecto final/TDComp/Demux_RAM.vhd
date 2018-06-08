----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:09:27 01/23/2018 
-- Design Name: 
-- Module Name:    Demux_RAM - Behavioral 
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

entity Demux_RAM is
	Port ( Input : in  STD_LOGIC_VECTOR (3 downto 0);
           Enable : in  STD_LOGIC;
           OutputA : out  STD_LOGIC_VECTOR (3 downto 0);
			  OutputB : out  STD_LOGIC_VECTOR (9 downto 0));
end Demux_RAM;

architecture Behavioral of Demux_RAM is

begin

	process(Input,Enable)
	begin
		if Enable = '0' then
			OutputA<="0000";
			OutputB<="000000"&Input;
		else
			OutputA<=Input;
			OutputB<="0000000000";
		end if;
	end process;

end Behavioral;

