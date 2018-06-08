----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:16:46 12/01/2017 
-- Design Name: 
-- Module Name:    RAM_DataPath_01 - Behavioral 
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

entity RAM_DataPath_01 is
    Port ( AddressRam : in  STD_LOGIC_VECTOR (3 downto 0);
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
			  CLK : in STD_LOGIC;
			  RESET : in STD_LOGIC;
           Sel_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           DataBus : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC;
           SalALU : out  STD_LOGIC_VECTOR (3 downto 0));
end RAM_DataPath_01;

architecture Behavioral of RAM_DataPath_01 is

COMPONENT RAM_16x4
	PORT(
		DataIn : IN std_logic_vector(3 downto 0);
		WE : IN std_logic;
		Address : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT DataPath_01
	PORT(
		DataBus : IN std_logic_vector(3 downto 0);
		SEL_ALU : IN std_logic_vector(1 downto 0);
		CLK : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		RESET : IN std_logic;          
		SalALU : OUT std_logic_vector(3 downto 0);
		SalREGA : OUT std_logic_vector(3 downto 0);
		SalREGB : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;

	signal Signal_SalALU :std_logic_vector(3 downto 0);
	signal Signal_DataBus :std_logic_vector(3 downto 0);

begin
	
	Inst_RAM_16x4: RAM_16x4 PORT MAP(
		DataIn => Signal_SalALU,
		WE => CW3,
		Address => AddressRam,
		DataOut => Signal_DataBus,
		CLK => CLK
	);

	Inst_DataPath_01: DataPath_01 PORT MAP(
		DataBus => Signal_DataBus,
		SEL_ALU => Sel_ALU,
		CLK => CLK,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		RESET => RESET,
		SalALU => Signal_SalALU,
		SalREGA => SalRegA,
		SalREGB => SalRegB,
		SalFZ => SalFZ
	);
	DataBus<=Signal_DataBus;
	SalALU<=Signal_SalALU;
	
end Behavioral;

