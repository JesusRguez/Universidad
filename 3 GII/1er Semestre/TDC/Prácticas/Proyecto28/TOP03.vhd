----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:13:30 12/13/2017 
-- Design Name: 
-- Module Name:    TOP03 - Behavioral 
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

entity TOP03 is
    Port ( AddressROM : in  STD_LOGIC_VECTOR (2 downto 0);
           Sel_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
           CW4 : in  STD_LOGIC;
           CW5 : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Instruction : out  STD_LOGIC_VECTOR (7 downto 0);
           --AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           --DataBus : out  STD_LOGIC_VECTOR (3 downto 0);
           --SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           --SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalCOP : out  STD_LOGIC_VECTOR (1 downto 0);
           SalFZ : out  STD_LOGIC;
			  Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
end TOP03;

architecture Behavioral of TOP03 is

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
	
	COMPONENT Display7Seg_4ON
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		Dato1 : IN std_logic_vector(3 downto 0);
		Dato2 : IN std_logic_vector(3 downto 0);
		Dato3 : IN std_logic_vector(3 downto 0);
		Dato4 : IN std_logic_vector(3 downto 0);          
		Anodo : OUT std_logic_vector(3 downto 0);
		Catodo : OUT std_logic_vector(6 downto 0)
		);
	END COMPONENT;
	
	signal salida_registroA: std_logic_vector(3 downto 0);
	signal salida_registroB: std_logic_vector(3 downto 0);
	signal senal_databus: std_logic_vector(3 downto 0);
	signal senal_AddressRAM: std_logic_vector(3 downto 0);

begin

	Inst_ROM_RAM_DataPath_01: ROM_RAM_DataPath_01 PORT MAP(
		AddressROM => AddressROM,
		CLK => CLK,
		RESET => RESET,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CW4 => CW4,
		CW5 => CW5,
		Sel_ALU => Sel_ALU,
		Instruction => Instruction,
		AddressRAM => senal_AddressRAM,
		SalCOP => SalCOP,
		DataBus => senal_databus,
		SalRegA => salida_registroA,
		SalRegB => salida_registroB,
		SalFZ => SalFZ
	);
	
	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Dato1 => salida_registroB,
		Dato2 => salida_registroA,
		Dato3 => senal_databus,
		Dato4 => senal_AddressRAM,
		Anodo => Anodo,
		Catodo => Catodo
	);
	
	
	

end Behavioral;

