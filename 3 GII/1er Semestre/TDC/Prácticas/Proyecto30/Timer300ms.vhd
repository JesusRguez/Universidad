----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:32:27 01/10/2018 
-- Design Name: 
-- Module Name:    Timer300ms - Behavioral 
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

entity Timer300ms is
    Port ( Enable : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           End300ms : out  STD_LOGIC);
end Timer300ms;

architecture Behavioral of Timer300ms is

	constant EndCount: integer:=15000000;
	signal Count: integer range 0 to EndCount;

begin
	
	process(CLK, RESET)
	begin
		if RESET='1' then
			Count<=0;
			End300ms<='0';
		elsif rising_edge(CLK) then
		if Enable = '1' then
			if Count = EndCount -1 then
				Count<=0;
				End300ms<='1';
			else
				Count<=Count+1;
				End300ms<='0';
			end if;
		end if;
		end if;
	end process;
	
end Behavioral;