----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:39:09 01/25/2018 
-- Design Name: 
-- Module Name:    TDComp - Behavioral 
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

entity TDComp is
	Port ( Push : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           FZ : out  STD_LOGIC;
			  COP : out  STD_LOGIC_VECTOR(2 downto 0);
			  Instruction : out  STD_LOGIC_VECTOR(9 downto 0);
			  SalidaALU : out  STD_LOGIC_VECTOR(3 downto 0);
			  SalidaRegA : out  STD_LOGIC_VECTOR(3 downto 0);
			  SalidaRegB : out  STD_LOGIC_VECTOR(3 downto 0);
			  AddressRAM : out  STD_LOGIC_VECTOR(3 downto 0));
end TDComp;

architecture Behavioral of TDComp is

	COMPONENT ControlUnit
	PORT(
		Push : IN std_logic;
		RESET : IN std_logic;
		CLK : IN std_logic;
		FZ : IN std_logic;
		COP : IN std_logic_vector(2 downto 0);          
		ControlWord : OUT std_logic_vector(14 downto 0)
		);
	END COMPONENT;

	COMPONENT PC_RAM_BancoDataPath
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
		CW7 : IN std_logic_vector(1 downto 0);
		CW8 : IN std_logic;
		CW9 : IN std_logic;
		CW10 : IN std_logic;
		CW11 : IN std_logic;
		CW12 : IN std_logic;
		CW13 : IN std_logic;          
		SalFZ : OUT std_logic;
		COP : OUT std_logic_vector(2 downto 0);
		Instruction : OUT std_logic_vector(9 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0);
		SalidaALU : OUT std_logic_vector(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal signalCW:std_logic_vector(14 downto 0);
	signal signalSalFZ:std_logic;
	signal signalCOP:std_logic_vector(2 downto 0);
	signal signalCW0and:std_logic;
	signal signalCW1and:std_logic;
	signal signalCW2and:std_logic;
	signal signalCW3and:std_logic;
	signal signalCW5and:std_logic;
	signal signalCW12and:std_logic;
	

begin

	
	
	Inst_ControlUnit: ControlUnit PORT MAP(
		Push => Push,
		RESET => RESET,
		CLK => CLK,
		FZ => signalSalFZ,
		COP => signalCOP,
		ControlWord => signalCW
	);
	
	--Señales con la operación AND hecha para evitar los rebotes
	signalCW0and<= Push and signalCW(0);
	signalCW1and<= Push and signalCW(1);
	signalCW2and<= Push and signalCW(2);
	signalCW3and<= Push and signalCW(3);
	signalCW5and<= Push and signalCW(5);
	signalCW12and<=Push and signalCW(13);
	
	Inst_PC_RAM_BancoDataPath: PC_RAM_BancoDataPath PORT MAP(
		CLK => CLK,
		RESET => RESET,
		CW0 => signalCW0and,
		CW1 => signalCW1and,
		CW2 => signalCW2and,
		CW3 => signalCW3and,
		CW4 => signalCW(4),
		CW5 => signalCW5and,
		CW6 => signalCW(6),
		CW7 => signalCW(8 downto 7),
		CW8 => signalCW(9),
		CW9 => signalCW(10),
		CW10 => signalCW(11),
		CW11 => signalCW(12),
		CW12 => signalCW12and,
		CW13 => signalCW(14),
		SalFZ => signalSalFZ,
		COP => signalCOP,
		Instruction => Instruction,
		AddressRAM => AddressRAM,
		SalidaALU => SalidaALu,
		SalidaRegA => SalidaRegA,
		SalidaRegB => SalidaRegB
	);
	
	COP<=signalCOP;
	FZ<=signalSalFZ;

end Behavioral;

