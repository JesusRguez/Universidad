----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:20:38 01/17/2018 
-- Design Name: 
-- Module Name:    DidaComp - Behavioral 
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

entity DidaComp is
    Port ( Push : in  STD_LOGIC;
			  CLK : in std_logic;
			  RESET : in std_logic;
           AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           AddressROM : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           COP : out  STD_LOGIC_VECTOR (1 downto 0);
           Instruction : out  STD_LOGIC_VECTOR (7 downto 0);
           FZ : out  STD_LOGIC);
end DidaComp;

architecture Behavioral of DidaComp is

	COMPONENT ControlUnit_DidaComp
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		Push : IN std_logic;
		COP : IN std_logic_vector(1 downto 0);
		FlagZero : IN std_logic;          
		ControlWord : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
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
		COP : OUT std_logic_vector(1 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;
	
	signal senalCU:std_logic_vector(9 downto 0);
	signal senalCW:std_logic_vector(7 downto 0);
	signal senalCOP:std_logic_vector(1 downto 0);
	signal senalCOPsalida:std_logic_vector(1 downto 0);
	signal senalFZ:std_logic;
	signal senalCW7and:std_logic;
	signal senalCW4and:std_logic;
	signal senalCW2and:std_logic;
	signal senalCW1and:std_logic;
	signal senalCW0and:std_logic;

begin

	Inst_ControlUnit_DidaComp: ControlUnit_DidaComp PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Push => Push,
		COP => senalCOPsalida,
		FlagZero => senalFZ,
		ControlWord => senalCU
	);
	
	senalCW <= senalCU(7 downto 0);
	senalCOP <= senalCU(9 downto 8);
	
	senalCW7and <= Push and senalCW(7);
	senalCW4and <= Push and senalCW(4);
	senalCW2and <= Push and senalCW(2);
	senalCW1and <= Push and senalCW(1);
	senalCW0and <= Push and senalCW(0);
	
	Inst_MicroArq_DidaComp: MicroArq_DidaComp PORT MAP(
		CLK => CLK,
		RESET => RESET,
		CW0 => senalCW0and,
		CW1 => senalCW1and,
		CW2 => senalCW2and,
		CW3 => senalCW(3),
		CW4 => senalCW4and,
		CW5 => senalCW(5),
		CW6 => senalCW(6),
		CW7 => senalCW7and,
		SelALU => senalCOP,
		RegInst => Instruction,
		AddressROM => AddressROM,
		AddressRAM => AddressRAM,
		SalRegA => SalRegA,
		SalRegB => SalRegB,
		COP => senalCOPsalida,
		SalFZ => senalFZ
	);
	
	COP <= senalCOPsalida;
	FZ <= senalFZ;

end Behavioral;

