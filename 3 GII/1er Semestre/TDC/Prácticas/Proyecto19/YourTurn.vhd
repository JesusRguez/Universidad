----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:57:59 11/15/2017 
-- Design Name: 
-- Module Name:    YourTurn - Behavioral 
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

entity YourTurn is
	Generic (M: INTEGER:=3);
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Push_Inc : in  STD_LOGIC;
           Count : out  STD_LOGIC_VECTOR (M downto 0));
end YourTurn;

architecture Behavioral of YourTurn is

	signal pulso:std_logic;

	COMPONENT RisingEdge
	PORT(
		RESET : IN std_logic;
		PUSH : IN std_logic;
		CLK : IN std_logic;          
		Pulse : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Counter_Nbits
	Generic (N: INTEGER);
	PORT(
		ENABLE : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		Q : OUT std_logic_vector(N downto 0)
		);
	END COMPONENT;

begin
	Inst_RisingEdge: RisingEdge PORT MAP(
		RESET => RESET,
		PUSH => Push_Inc,
		CLK => CLK,
		Pulse => pulso
	);
	
	Inst_Counter_Nbits: Counter_Nbits generic map (N => M) PORT MAP(
		ENABLE => pulso,
		CLK => CLK,
		RESET => RESET,
		Q => Count
	);
end Behavioral;

