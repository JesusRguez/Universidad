----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:17:05 01/25/2018 
-- Design Name: 
-- Module Name:    TOP - Behavioral 
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

entity TOP is
    Port ( Push : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           Instruction : out  STD_LOGIC_VECTOR (9 downto 0);
           FZ : out  STD_LOGIC;
			  COP : out  STD_LOGIC_VECTOR (2 downto 0);--Redundante debido a que los leds cogen el código de instrucción del Instruction
           Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
end TOP;

architecture Behavioral of TOP is

	COMPONENT RisingEdge
	PORT(
		RESET : IN std_logic;
		PUSH : IN std_logic;
		CLK : IN std_logic;          
		Pulse : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT TDComp
	PORT(
		Push : IN std_logic;
		RESET : IN std_logic;
		CLK : IN std_logic;          
		FZ : OUT std_logic;
		COP : OUT std_logic_vector(2 downto 0);
		Instruction : OUT std_logic_vector(9 downto 0);
		SalidaALU : OUT std_logic_vector(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0)
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
	
	signal senalPulse:std_logic;
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
	
	Inst_TDComp: TDComp PORT MAP(
		Push => senalPulse,
		RESET => RESET,
		CLK => CLK,
		FZ => FZ,
		COP => COP,
		Instruction => Instruction,
		SalidaALU => senalDato1,
		SalidaRegA => senalDato3,
		SalidaRegB => senalDato2,
		AddressRAM => senalDato4
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

