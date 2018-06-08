----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:41:31 12/01/2017 
-- Design Name: 
-- Module Name:    TOP02 - Behavioral 
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

entity TOP02 is
    Port ( AddressRAM : in  STD_LOGIC_VECTOR (3 downto 0);
           Sel_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
           --DataBus : out  STD_LOGIC_VECTOR (3 downto 0);
			  Anodo : out STD_LOGIC_VECTOR (3 downto 0);
			  Catodo : out STD_LOGIC_VECTOR (6 downto 0);
           --SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           --SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           --SalALU : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
end TOP02;

architecture Behavioral of TOP02 is

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
	
	signal Signal_DataBus :std_logic_vector(3 downto 0);
	signal Signal_SalRegA :std_logic_vector(3 downto 0);
	signal Signal_SalRegB :std_logic_vector(3 downto 0);
	signal Signal_SalALU :std_logic_vector(3 downto 0);
	
	

begin

	Inst_RAM_DataPath_01: RAM_DataPath_01 PORT MAP(
		AddressRam => AddressRam,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CLK => CLK,
		RESET => RESET,
		Sel_ALU => Sel_ALU,
		DataBus => Signal_DataBus,
		SalRegA => Signal_SalRegA,
		SalRegB => Signal_SalRegB,
		SalFZ => SalFZ,
		SalALU => Signal_SalALU
	);
	
	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Dato1 => Signal_DataBus,
		Dato2 => Signal_SalRegA,
		Dato3 => Signal_SalRegB,
		Dato4 => Signal_SalALU,
		Anodo => Anodo,
		Catodo => Catodo
	);

end Behavioral;

