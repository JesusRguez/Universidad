----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:49:46 12/15/2017 
-- Design Name: 
-- Module Name:    MicroArq_DidaComp - Behavioral 
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

entity MicroArq_DidaComp is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
           CW4 : in  STD_LOGIC;
           CW5 : in  STD_LOGIC;
           CW6 : in  STD_LOGIC;
           CW7 : in  STD_LOGIC;
           SelALU : in  STD_LOGIC_VECTOR (1 downto 0);
           RegInst : out  STD_LOGIC_VECTOR (7 downto 0);
           AddressROM : out  STD_LOGIC_VECTOR (3 downto 0);
           AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
			  --DataBus : out  STD_LOGIC_VECTOR (3 downto 0);
           COP : out  STD_LOGIC_VECTOR (1 downto 0);
           SalFZ : out  STD_LOGIC);
end MicroArq_DidaComp;

architecture Behavioral of MicroArq_DidaComp is

	COMPONENT ROM_RAM_DataPath_01
	PORT(
		AddressROM : IN std_logic_vector(2 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		CW3 : IN std_logic;
		CW4 : IN std_logic;
		CW5 : IN std_logic;
		Sel_ALU : IN std_logic_vector(1 downto 0);          
		Instruction : OUT std_logic_vector(7 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0);
		SalCOP : OUT std_logic_vector(1 downto 0);
		DataBus : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Reg_3bits
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(2 downto 0);
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(2 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Inc_3bits
	PORT(
		Value : IN std_logic_vector(2 downto 0);       
		Value_Inc : OUT std_logic_vector(2 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Mux2_3bits
	PORT(
		A : IN std_logic_vector(2 downto 0);
		B : IN std_logic_vector(2 downto 0);
		Sel : IN std_logic;          
		Z : OUT std_logic_vector(2 downto 0)
		);
	END COMPONENT;
	
	signal signal_PCinc : std_logic_vector(2 downto 0);
	signal signal_AddressJump : std_logic_vector(2 downto 0);
	signal signal_instruction : std_logic_vector(7 downto 0);
	signal MUX_PC : std_logic_vector(2 downto 0);
	signal signal_PC_ROM : std_logic_vector(2 downto 0);

begin

	Inst_ROM_RAM_DataPath_01: ROM_RAM_DataPath_01 PORT MAP(
		AddressROM => signal_PC_ROM,
		CLK => CLK,
		RESET => RESET,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CW4 => CW4,
		CW5 => CW5,
		Sel_ALU => SelALU,
		Instruction => signal_instruction,
		AddressRAM => AddressRAM,
		SalCOP => COP,
		DataBus => open,
		SalRegA => SalRegA,
		SalRegB => SalRegB,
		SalFZ => SalFZ 
	);
	RegInst<=signal_instruction;
	signal_AddressJump<=signal_instruction(2 downto 0);
	
	Inst_Reg_3bits: Reg_3bits PORT MAP(
		CLK => CLK,
		RESET => RESET,
		DataIn => MUX_PC,
		ENABLE => CW7,
		DataOut => signal_PC_ROM
	);
	
	Inst_Inc_3bits: Inc_3bits PORT MAP(
		Value => signal_PC_ROM,
		Value_Inc => signal_PCinc
	);
	
	Inst_Mux2_3bits: Mux2_3bits PORT MAP(
		A => signal_PCinc,
		B => signal_AddressJump,
		Sel => CW6,
		Z => MUX_PC
	);
	
	AddressROM<='0'&signal_PC_ROM;

end Behavioral;

