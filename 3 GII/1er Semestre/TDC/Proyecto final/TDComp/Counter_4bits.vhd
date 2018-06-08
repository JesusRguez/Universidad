----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:51:05 01/23/2018 
-- Design Name: 
-- Module Name:    Counter_4bits - Behavioral 
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

entity Counter_4bits is
	Port ( AddressJump : in  STD_LOGIC_VECTOR (3 downto 0);
			  CLK : in  STD_LOGIC;
			  RESET : in  STD_LOGIC;
           CW11 : in  STD_LOGIC;
			  CW12 : in  STD_LOGIC;
			  CW13 : in  STD_LOGIC;
           PC_RAM : out  STD_LOGIC_VECTOR (3 downto 0));
end Counter_4bits;

architecture Behavioral of Counter_4bits is

	COMPONENT Reg_4bits
	PORT(
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Inc_4bits
	PORT(
		Value : IN std_logic_vector(3 downto 0);          
		Value_Inc : OUT std_logic_vector(3 downto 0)
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
	
	signal signal_PC_RAM:std_logic_vector(3 downto 0);
	signal signal_PCInc:std_logic_vector(3 downto 0);
	signal signal_MUX_PC:std_logic_vector(3 downto 0);
	signal signalEntradaRAM:std_logic_vector(3 downto 0);

begin

	Inst_Inc_4bits: Inc_4bits PORT MAP(
		Value => signal_PC_RAM,
		Value_Inc => signal_PCInc
	);
	
	Inst_Reg_4bits: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => signal_MUX_PC,
		CLK => CLK,
		ENABLE => CW12,
		DataOut => signal_PC_RAM
	);
	
	Inst_Mux2_4bits: Mux2_4bits PORT MAP(
		A => AddressJump,
		B => signal_PCInc,
		Sel => CW11,
		Z => signal_MUX_PC
	);
	
	Inst_Mux2_4bits_DataAddress: Mux2_4bits PORT MAP(
		A => AddressJump,
		B => signal_PC_RAM,
		Sel => CW13,
		Z => signalEntradaRAM
	);
	
	PC_RAM<=signalEntradaRAM;

end Behavioral;

