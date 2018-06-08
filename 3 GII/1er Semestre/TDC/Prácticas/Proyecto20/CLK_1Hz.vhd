----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:17:05 11/15/2017 
-- Design Name: 
-- Module Name:    CLK_1Hz - Behavioral 
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

entity CLK_1Hz is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Out_1Hz : out  STD_LOGIC);
end CLK_1Hz;

architecture Behavioral of CLK_1Hz is

	constant EndCount: integer:=50000000;
	signal Count: integer range 0 to EndCount;

begin
	
	process(CLK, RESET)
	begin
		if RESET='1' then
			Count<=0;
			Out_1Hz<='0';
		elsif rising_edge(CLK) then
			if Count = EndCount -1 then
				Count<=0;
				Out_1Hz<='1';
			else
				Count<=Count+1;
				Out_1Hz<='0';
			end if;
		end if;
	end process;
	
end Behavioral;

