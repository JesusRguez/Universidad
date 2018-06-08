----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:22:05 11/22/2017 
-- Design Name: 
-- Module Name:    DataPath_01 - Behavioral 
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

entity DataPath_01 is
    Port ( DataBus : in  STD_LOGIC_VECTOR (3 downto 0);
           SEL_ALU : in  STD_LOGIC_VECTOR (1 downto 0);
           CLK : in  STD_LOGIC;
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           SalALU : out  STD_LOGIC_VECTOR (3 downto 0);
           SalREGA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalREGB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
end DataPath_01;

architecture Behavioral of DataPath_01 is

	COMPONENT Reg_4bits
	PORT(
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT ALU_4bits
	PORT(
		OPE_A : IN std_logic_vector(3 downto 0);
		OPE_B : IN std_logic_vector(3 downto 0);
		SEL_ALU : IN std_logic_vector(1 downto 0);          
		Sal_ALU : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT FFD
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		ENABLE : IN std_logic;
		D : IN std_logic;          
		Q : OUT std_logic
		);
	END COMPONENT;
	
	signal RGA_ALU :STD_LOGIC_VECTOR(3 downto 0);
	signal RGB_ALU :STD_LOGIC_VECTOR(3 downto 0);
	signal FlagZero :std_logic;

begin

	REGA: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => DataBus,
		CLK => CLK,
		ENABLE => CW0,
		DataOut => RGA_ALU
	);
	SalREGA<=RGA_ALU;

	REGB: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => DataBus,
		CLK => CLK,
		ENABLE => CW1,
		DataOut => RGB_ALU
	);
	SalREGB<=RGB_ALU;

	Inst_ALU_4bits: ALU_4bits PORT MAP(
		OPE_A => RGA_ALU,
		OPE_B => RGB_ALU,
		SEL_ALU => SEL_ALU,
		Sal_ALU => SalALU,
		SalFZ => FlagZero
	);
	
	Inst_FFD: FFD PORT MAP(
		CLK => CLK,
		RESET => RESET,
		ENABLE => CW2,
		D => FlagZero,
		Q => SalFZ
	);

end Behavioral;

