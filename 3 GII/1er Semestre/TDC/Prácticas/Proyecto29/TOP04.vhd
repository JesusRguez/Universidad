----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:50:10 12/20/2017 
-- Design Name: 
-- Module Name:    TOP04 - Behavioral 
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

entity TOP04 is
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
           SelALU : IN std_logic_vector(1 downto 0);
           RegInst : out  STD_LOGIC_VECTOR (7 downto 0);
           AddressROM : out  STD_LOGIC_VECTOR (3 downto 0);
           AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           COP : out  STD_LOGIC_VECTOR (1 downto 0);
           SalFZ : out  STD_LOGIC;
			  Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
end TOP04;

architecture Behavioral of TOP04 is

	COMPONENT MicroArq_DidaComp
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		CW3 : IN std_logic;
		CW4 : IN std_logic;
		CW5 : IN std_logic;
		CW6 : IN std_logic;
		CW7 : IN std_logic;
		SelALU : IN std_logic_vector(1 downto 0);          
		RegInst : OUT std_logic_vector(7 downto 0);
		AddressROM : OUT std_logic_vector(3 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		--DataBus : OUT std_logic_vector(3 downto 0);
		COP : OUT std_logic_vector(1 downto 0);
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
	signal senal_AddressROM: std_logic_vector(3 downto 0);
	signal senal_AddressRAM: std_logic_vector(3 downto 0);

begin

	Inst_MicroArq_DidaComp: MicroArq_DidaComp PORT MAP(
		CLK => CLK,
		RESET => RESET,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CW4 => CW4,
		CW5 => CW5,
		CW6 => CW6,
		CW7 => CW7,
		SelALU => SelALU,
		RegInst => RegInst,
		AddressROM => senal_AddressROM,
		AddressRAM => senal_AddressRAM,
		SalRegA => salida_registroA,
		SalRegB => salida_registroB,
		COP => COP,
		SalFZ => SalFZ
	);
	
	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Dato1 => senal_AddressROM,
		Dato2 => senal_AddressRAM,
		Dato3 => salida_registroA,
		Dato4 => salida_registroB,
		Anodo => Anodo,
		Catodo => Catodo
	);
	
	AddressROM<=senal_AddressROM;
	AddressRAM<=senal_AddressRAM;
	SalRegA<=salida_registroA;
	SalRegB<=salida_registroB;

end Behavioral;

