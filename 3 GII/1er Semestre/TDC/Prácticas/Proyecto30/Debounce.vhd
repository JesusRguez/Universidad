----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:59:28 01/10/2018 
-- Design Name: 
-- Module Name:    Debounce - Behavioral 
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

entity Debounce is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Push : in  STD_LOGIC;
           FilteredPush : out  STD_LOGIC);
end Debounce;

architecture Behavioral of Debounce is

COMPONENT DebounceFSM
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		Flag_Timer : IN std_logic;
		Push : IN std_logic;          
		EnableTimer : OUT std_logic;
		FilteredPush : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Timer300ms
	PORT(
		Enable : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		End300ms : OUT std_logic
		);
	END COMPONENT;
	
	signal Signal_EnableTimer: std_logic;
	signal Signal_End300ms: std_logic;

begin

	Inst_DebounceFSM: DebounceFSM PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Flag_Timer => Signal_End300ms,
		Push => Push,
		EnableTimer => Signal_EnableTimer,
		FilteredPush => FilteredPush
	);
	
	Inst_Timer300ms: Timer300ms PORT MAP(
		Enable => Signal_EnableTimer,
		CLK => CLK,
		RESET => RESET,
		End300ms => Signal_End300ms
	);

end Behavioral;

