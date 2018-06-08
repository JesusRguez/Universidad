----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:17:53 11/10/2017 
-- Design Name: 
-- Module Name:    ON_OFF - Behavioral 
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

entity ON_OFF is
    Port ( Button : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Toggle_out : out  STD_LOGIC);
end ON_OFF;

architecture Behavioral of ON_OFF is

COMPONENT RisingEdge
	PORT(
		RESET : IN std_logic;
		PUSH : IN std_logic;
		CLK : IN std_logic;          
		Pulse : OUT std_logic
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
	
	signal pulse_enable: std_logic;
	
begin
	Inst_RisingEdge: RisingEdge PORT MAP(
		RESET => RESET,
		PUSH => Button,
		CLK => CLK,
		Pulse => pulse_enable
	);
	
	Inst_Toggle: Toggle PORT MAP(
		CLK => pulse_enable,
		RESET => RESET,
		ENABLE => pulse_enable,
		Q => Toggle_out
	);
	
			
end Behavioral;

