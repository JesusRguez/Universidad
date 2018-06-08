----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:52:49 11/17/2017 
-- Design Name: 
-- Module Name:    BlinkLED - Behavioral 
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

entity BlinkLED is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Q : out  STD_LOGIC);
end BlinkLED;

architecture Behavioral of BlinkLED is

	signal Signal_Out_1Hz:std_logic;

	COMPONENT CLK_1Hz
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;          
		Out_1Hz : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Toggle
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		ENABLE : IN std_logic;          
		Q : OUT std_logic
		);
	END COMPONENT;

begin

	Inst_CLK_1Hz: CLK_1Hz PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Out_1Hz => Signal_Out_1Hz
	);
	
	Inst_Toggle: Toggle PORT MAP(
		CLK => CLK,
		RESET => RESET,
		ENABLE => Signal_Out_1Hz,
		Q => Q
	);

end Behavioral;