----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:38:17 01/21/2018 
-- Design Name: 
-- Module Name:    DataPath - Behavioral 
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

entity DataPath is
    Port ( DataBus : in  STD_LOGIC_VECTOR (3 downto 0);
           COP : in  STD_LOGIC_VECTOR (2 downto 0);
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CW0 : in  STD_LOGIC;
           CW1 : in  STD_LOGIC;
           CW2 : in  STD_LOGIC;
           SalALU : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalRegB : out  STD_LOGIC_VECTOR (3 downto 0);
           SalFZ : out  STD_LOGIC);
end DataPath;

architecture Behavioral of DataPath is

	COMPONENT ALU
	PORT(
		OPE_A : IN std_logic_vector(3 downto 0);
		OPE_B : IN std_logic_vector(3 downto 0);
		COP : IN std_logic_vector(2 downto 0);          
		SalALU : OUT std_logic_vector(3 downto 0);
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
	
	COMPONENT Reg_4bits
	PORT(
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal signalSalRegA:std_logic_vector(3 downto 0);
	signal signalSalRegB:std_logic_vector(3 downto 0);
	signal signalSalFZ:std_logic;

begin
	
	Inst_ALU: ALU PORT MAP(
		OPE_A => DataBus,
		OPE_B => DataBus,
		COP => COP,
		SalALU => SalALU,
		SalFZ => signalSalFZ
	);
	
	Inst_FFD: FFD PORT MAP(
		CLK => CLK,
		RESET => RESET,
		ENABLE => CW2,
		D => signalSalFZ,
		Q => SalFZ
	);
	
	REGA: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => DataBus,
		CLK => CLK,
		ENABLE => CW0,
		DataOut => signalSalRegA
	);
	
	REGB: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => DataBus,
		CLK => CLK,
		ENABLE => CW1,
		DataOut => signalSalRegB
	);
	
	SalRegA<=signalSalRegA;
	SalRegB<=signalSalRegB;

end Behavioral;

