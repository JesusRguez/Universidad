----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:47:40 11/15/2017 
-- Design Name: 
-- Module Name:    Counter_Nbits - Behavioral 
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

entity Counter_Nbits is
	Generic (N: INTEGER:=2);
    Port ( ENABLE : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC_VECTOR (N downto 0));
end Counter_Nbits;

architecture Behavioral of Counter_Nbits is
	signal CUENTA: unsigned (N downto 0);

begin
	process(CLK, RESET)
	begin
		if RESET = '1' then
			CUENTA<=(others=>'0');
			elsif rising_edge(CLK) then
				if ENABLE='1' then
					CUENTA <= CUENTA +1;
				end if;
			end if;
	end process;
	
	Q<=STD_LOGIC_VECTOR(CUENTA);
end Behavioral;

