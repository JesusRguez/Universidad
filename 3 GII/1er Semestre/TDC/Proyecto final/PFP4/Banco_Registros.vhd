----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    13:21:25 01/21/2018 
-- Design Name: 
-- Module Name:    Banco_Registros - Behavioral 
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

entity Banco_Registros is
    Port ( DirA : in  STD_LOGIC_VECTOR (2 downto 0);
           DirB : in  STD_LOGIC_VECTOR (2 downto 0);
           Data_IN : in  STD_LOGIC_VECTOR (3 downto 0);
           CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CW3 : in  STD_LOGIC;
			  SalDirA : out  STD_LOGIC_VECTOR (3 downto 0);
           SalDirB : out  STD_LOGIC_VECTOR (3 downto 0));
end Banco_Registros;

architecture Behavioral of Banco_Registros is

	COMPONENT Reg_4bits
	PORT(
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Deco3to8
	PORT(
		Input : IN std_logic_vector(2 downto 0);
		Enable : IN std_logic;          
		Output : OUT std_logic_vector(7 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Mux8_4bits
	PORT(
		R1 : IN std_logic_vector(3 downto 0);
		R2 : IN std_logic_vector(3 downto 0);
		R3 : IN std_logic_vector(3 downto 0);
		R4 : IN std_logic_vector(3 downto 0);
		R5 : IN std_logic_vector(3 downto 0);
		R6 : IN std_logic_vector(3 downto 0);
		R7 : IN std_logic_vector(3 downto 0);
		R8 : IN std_logic_vector(3 downto 0);
		SelReg : IN std_logic_vector(2 downto 0);          
		Z : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal signalSalidaDeco:std_logic_vector(7 downto 0);
	signal signalSalR1:std_logic_vector(3 downto 0);
	signal signalSalR2:std_logic_vector(3 downto 0);
	signal signalSalR3:std_logic_vector(3 downto 0);
	signal signalSalR4:std_logic_vector(3 downto 0);
	signal signalSalR5:std_logic_vector(3 downto 0);
	signal signalSalR6:std_logic_vector(3 downto 0);
	signal signalSalR7:std_logic_vector(3 downto 0);
	signal signalSalR8:std_logic_vector(3 downto 0);

begin

	Inst_Deco3to8: Deco3to8 PORT MAP(
		Input => DirB,
		Enable => CW3,
		Output => signalSalidaDeco
	);

	R1: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(0),
		DataOut => signalSalR1
	);
	
	R2: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(1),
		DataOut => signalSalR2
	);
	
	R3: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(2),
		DataOut => signalSalR3
	);
	
	R4: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(3),
		DataOut => signalSalR4
	);
	
	R5: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(4),
		DataOut => signalSalR5
	);
	
	R6: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(5),
		DataOut => signalSalR6
	);
	
	R7: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(6),
		DataOut => signalSalR7
	);
	
	R8: Reg_4bits PORT MAP(
		RESET => RESET,
		DataIn => Data_In,
		CLK => CLK,
		ENABLE => signalSalidaDeco(7),
		DataOut => signalSalR8
	);
	
	MuxDirA: Mux8_4bits PORT MAP(
		R1 => signalSalR1,
		R2 => signalSalR2,
		R3 => signalSalR3,
		R4 => signalSalR4,
		R5 => signalSalR5,
		R6 => signalSalR6,
		R7 => signalSalR7,
		R8 => signalSalR8,
		SelReg => DirA,
		Z => SalDirA
	);
	
	MuxDirB: Mux8_4bits PORT MAP(
		R1 => signalSalR1,
		R2 => signalSalR2,
		R3 => signalSalR3,
		R4 => signalSalR4,
		R5 => signalSalR5,
		R6 => signalSalR6,
		R7 => signalSalR7,
		R8 => signalSalR8,
		SelReg => DirB,
		Z => SalDirB
	);


end Behavioral;

