----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:06:59 11/17/2017 
-- Design Name: 
-- Module Name:    BlinkLED_2Process - Behavioral 
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

entity BlinkLED_2Process is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end BlinkLED_2Process;

architecture Behavioral of BlinkLED_2Process is

constant EndCount:integer:=50000000;
signal Count:integer range 0 to EndCount;
signal out_1Hz:std_logic;
signal CLK_1Hz:std_logic;

begin

	Counter:process(CLK, RESET)
	begin
		if RESET = '1' then
			Count<=0;
			Out_1Hz<='0';
		elsif rising_edge(CLK) then
			if Count=EndCount-1 then
				Count<=0;
				Out_1Hz<='1';
			else
				Count<=Count+1;
				Out_1Hz<='0';
			end if;
		end if;
	end process;
	
	FFT:process(CLK, RESET)
	begin
		if RESET = '1' then
			CLK_1Hz<='0';
		elsif rising_edge(CLK) then
			if Out_1Hz='1' then
				CLK_1Hz<=not CLK_1Hz;
			end if;
		end if;
	end process;
	
	Q<=CLK_1Hz;

end Behavioral;

