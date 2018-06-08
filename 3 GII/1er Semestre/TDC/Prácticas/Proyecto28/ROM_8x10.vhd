----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:37:18 12/05/2017 
-- Design Name: 
-- Module Name:    ROM_8x10 - Behavioral 
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

entity ROM_8x10 is
    Port ( Address : in  STD_LOGIC_VECTOR (2 downto 0);
           CLK : in  STD_LOGIC;
           Enable : in  STD_LOGIC;
           DataOut : out  STD_LOGIC_VECTOR (9 downto 0));
end ROM_8x10;

architecture Behavioral of ROM_8x10 is

type rom_type is array (7 downto 0) of std_logic_vector(9 downto 0);
constant ROM:rom_type:=(
	0=>"1010000011",
	1=>"0000010100",
	2=>"1000001001",
	3=>"1100010001",
	4=>"0100110111",
	5=>"0001000000",
	6=>"0000000000",
	7=>"0000000000");

begin

	process(CLK)
	begin
		if rising_edge(CLK) then
			if Enable='1' then
				DataOut<=ROM(to_integer(unsigned(Address)));
			end if;
		end if;
	end process;

end Behavioral;

