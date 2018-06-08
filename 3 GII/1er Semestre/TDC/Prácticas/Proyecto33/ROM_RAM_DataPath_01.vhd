----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:25:36 12/13/2017 
-- Design Name: 
-- Module Name:    ROM_RAM_DataPath_01 - Behavioral 
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

entity ROM_RAM_DataPath_01 is
    Port ( AddressROM : in  STD_LOGIC_VECTOR (2 downto 0);
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
			  CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
           CW4 : in  STD_LOGIC;
           CW5 : in  STD_LOGIC;
           Sel_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           Instruction : out  STD_LOGIC_VECTOR (7 downto 0);
           AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           SalCOP : out  STD_LOGIC_VECTOR (1 downto 0);
           DataBus : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
end ROM_RAM_DataPath_01;

architecture Behavioral of ROM_RAM_DataPath_01 is

COMPONENT RAM_DataPath_01
	PORT(
		AddressRam : IN std_logic_vector(3 downto 0);
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		CW3 : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;
		Sel_ALU : IN std_logic_vector(1 downto 0);          
		DataBus : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic;
		SalALU : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT ROM_8x10
	PORT(
		Address : IN std_logic_vector(2 downto 0);
		CLK : IN std_logic;
		Enable : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Reg_10bits
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(9 downto 0);
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Mux2_4bits
	PORT(
		A : IN std_logic_vector(3 downto 0);
		B : IN std_logic_vector(3 downto 0);
		Sel : IN std_logic;          
		Z : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal ROM_RegInst: std_logic_vector (9 downto 0);
	signal RegInst_MUX: std_logic_vector (9 downto 0);
	signal MUX_RAM: std_logic_vector (3 downto 0);

begin

Inst_RAM_DataPath_01: RAM_DataPath_01 PORT MAP(
		AddressRam => MUX_RAM,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CLK => CLK,
		RESET => RESET,
		Sel_ALU => Sel_ALU,
		DataBus => DataBus,
		SalRegA => SalRegA,
		SalRegB => SalRegB,
		SalFZ => SalFZ,
		SalALU =>open
	);
	
	Inst_ROM_8x10: ROM_8x10 PORT MAP(
		Address => AddressROM,
		CLK => CLK,
		Enable => '1',
		DataOut => ROM_RegInst
	);
	
	Inst_Reg_10bits: Reg_10bits PORT MAP(
		CLK => CLK,
		RESET => RESET,
		DataIn => ROM_RegInst,
		ENABLE => CW4,
		DataOut => RegInst_MUX
		
	);
	
	Inst_Mux2_4bits: Mux2_4bits PORT MAP(
		A => RegInst_MUX(3 downto 0),
		B => RegInst_MUX(7 downto 4),
		Sel => CW5,
		Z => Mux_RAM
	);
	
	Instruction<=RegInst_MUX(7 downto 0);
	AddressRAM<=MUX_RAM;
	SalCOP<=RegInst_MUX(9 downto 8);

end Behavioral;

