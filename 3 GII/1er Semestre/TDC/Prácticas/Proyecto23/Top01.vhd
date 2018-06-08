----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:02:34 11/22/2017 
-- Design Name: 
-- Module Name:    Top01 - Behavioral 
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

entity Top01 is
	Port ( DataBus : in  STD_LOGIC_VECTOR (3 downto 0);
           SEL_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           CLK : in  STD_LOGIC;
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           SalFZ : out  STD_LOGIC;
			  Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
end Top01;

architecture Behavioral of Top01 is

	COMPONENT DataPath_01
	PORT(
		DataBus : IN std_logic_vector(3 downto 0);
		SEL_ALU : IN std_logic_vector(1 downto 0);
		CLK : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		RESET : IN std_logic;          
		SalALU : OUT std_logic_vector(3 downto 0);
		SalREGA : OUT std_logic_vector(3 downto 0);
		SalREGB : OUT std_logic_vector(3 downto 0);
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
	
	signal Salida_ALU:std_logic_vector(3 downto 0);
	signal Salida_de_REGA:std_logic_vector(3 downto 0);
	signal Salida_de_REGB:std_logic_vector(3 downto 0);
	

begin

	Inst_DataPath_01: DataPath_01 PORT MAP(
		DataBus => DataBus,
		SEL_ALU => SEL_ALU,
		CLK => CLK,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		RESET => RESET,
		SalALU => Salida_ALU,
		SalREGA => Salida_de_REGA,
		SalREGB => Salida_de_REGB,
		SalFZ => SalFZ
	);
	
	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Dato1 => Salida_de_REGA,
		Dato2 => Salida_de_REGB,
		Dato3 => Salida_ALU,
		Dato4 => "0000",
		Anodo => Anodo,
		Catodo => Catodo
	);

end Behavioral;

