----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:48:42 01/17/2018 
-- Design Name: 
-- Module Name:    TOP05 - Behavioral 
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

entity TOP05 is
    Port ( Push : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Instruction : out  STD_LOGIC_VECTOR (7 downto 0);
           --AddressROM : out  STD_LOGIC_VECTOR (3 downto 0);
           --AddressRAM : out  STD_LOGIC_VECTOR (3 downto 0);
           --RegA : out  STD_LOGIC_VECTOR (3 downto 0);
           --RegB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalCOP : out  STD_LOGIC_VECTOR (1 downto 0);
           SalFZ : out  STD_LOGIC;
			  Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
end TOP05;

architecture Behavioral of TOP05 is

	COMPONENT RisingEdge
	PORT(
		RESET : IN std_logic;
		PUSH : IN std_logic;
		CLK : IN std_logic;          
		Pulse : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT DidaComp
	PORT(
		Push : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		AddressRAM : OUT std_logic_vector(3 downto 0);
		AddressROM : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		COP : OUT std_logic_vector(1 downto 0);
		Instruction : OUT std_logic_vector(7 downto 0);
		FZ : OUT std_logic
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
	
	signal senalPulse : std_logic;
	signal senalDato1 : std_logic_vector(3 downto 0);
	signal senalDato2 : std_logic_vector(3 downto 0);
	signal senalDato3 : std_logic_vector(3 downto 0);
	signal senalDato4 : std_logic_vector(3 downto 0);

begin
	
	Inst_RisingEdge: RisingEdge PORT MAP(
		RESET => RESET,
		PUSH => Push,
		CLK => CLK,
		Pulse => senalPulse
	);
	
	Inst_DidaComp: DidaComp PORT MAP(
		Push => senalPulse,
		CLK => CLK,
		RESET => RESET,
		AddressRAM => senalDato3,
		AddressROM => senalDato4,
		SalRegA => senalDato2,
		SalRegB => senalDato1,
		COP => SalCOP,
		Instruction => Instruction,
		FZ => SalFZ
	);
	
	
	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Dato1 => senalDato1,
		Dato2 => senalDato2,
		Dato3 => senalDato3,
		Dato4 => senalDato4,
		Anodo => Anodo,
		Catodo => Catodo
	);
	

end Behavioral;

