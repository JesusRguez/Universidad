----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:00:05 01/21/2018 
-- Design Name: 
-- Module Name:    RAM_Banco_DataPath - Behavioral 
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

entity RAM_Banco_DataPath is
    Port ( AddressRAM : in  STD_LOGIC_VECTOR(3 downto 0);
			  CLK : in  STD_LOGIC;
			  RESET : in  STD_LOGIC;
			  CW0 : in  STD_LOGIC;--regA
			  CW1 : in  STD_LOGIC;--regB
			  CW2 : in  STD_LOGIC;--FZ
			  CW3 : in  STD_LOGIC;--BancoRegistros
           CW4 : in  STD_LOGIC;--RAM
			  CW5 : in  STD_LOGIC;--RegInstrucciones
			  CW6 : in  STD_LOGIC;--DemuxRAM
			  CW7 : in  STD_LOGIC_VECTOR(1 downto 0);--Selector de DirA
			  CW8 : in  STD_LOGIC;--MuxRegA
			  CW9 : in  STD_LOGIC;--MuxDatoBanco
			  CW10 : in  STD_LOGIC;--DemuxRAM
			  SalFZ : out  STD_LOGIC;
			  COP : out  STD_LOGIC_VECTOR(2 downto 0);
			  AddressRAMOUT : out  STD_LOGIC_VECTOR(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0));
end RAM_Banco_DataPath;

architecture Behavioral of RAM_Banco_DataPath is

	COMPONENT Reg_10bits
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(9 downto 0);
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Demux_RAM
	PORT(
		Input : IN std_logic_vector(3 downto 0);
		Enable : IN std_logic;          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT RAM_16x10
	PORT(
		Address : IN std_logic_vector(3 downto 0);
		DataIn : IN std_logic_vector(9 downto 0);
		Enable : IN std_logic;
		CLK : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Deco1to2
	PORT(
		Input : IN std_logic_vector(9 downto 0);
		Enable : IN std_logic;          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Mux2_3bits
	PORT(
		A : IN std_logic_vector(2 downto 0);
		B : IN std_logic_vector(2 downto 0);
		Sel : IN std_logic;          
		Z : OUT std_logic_vector(2 downto 0)
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
	
	COMPONENT DataPath
	PORT(
		InRegA : IN std_logic_vector(3 downto 0);
		InRegB : IN std_logic_vector(3 downto 0);
		COP : IN std_logic_vector(2 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;          
		SalALU : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Deco2to4
	PORT(
		Input : IN std_logic_vector(3 downto 0);
		Enable : IN std_logic_vector(1 downto 0);          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(2 downto 0);
		OutputC : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Banco_Registros
	PORT(
		DirA : IN std_logic_vector(2 downto 0);
		DirB : IN std_logic_vector(2 downto 0);
		Data_IN : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW3 : IN std_logic;          
		SalDirA : OUT std_logic_vector(3 downto 0);
		SalDirB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal signalSalRegInst:std_logic_vector(9 downto 0);
	signal signalSalALU:std_logic_vector(3 downto 0);
	signal signalSalRAM:std_logic_vector(9 downto 0);
	signal signalDatoBanco:std_logic_vector(3 downto 0);
	signal signalRegInst:std_logic_vector(9 downto 0);
	signal signalSaltoBanco:std_logic_vector(2 downto 0);
	signal signalSaltoInm:std_logic_vector(3 downto 0);
	signal signalSalBancotoRegA:std_logic_vector(3 downto 0);
	signal signalSaltoRegA:std_logic_vector(3 downto 0);
	signal signalSalBancotoRegB:std_logic_vector(3 downto 0);
	signal signalSalFZ:std_logic;
	signal signalEntradaBanco:std_logic_vector(3 downto 0);
	signal signalEntradaRAM:std_logic_vector(9 downto 0);
	signal signalMuxBanco:std_logic_vector(3 downto 0);

begin

	Inst_Reg_10bits: Reg_10bits PORT MAP(
		CLK => CLK,
		RESET => RESET,
		DataIn => signalRegInst,
		ENABLE => CW5,
		DataOut => signalSalRegInst
	);
	
	Inst_Demux_RAM: Demux_RAM PORT MAP(
		Input => signalSalALU,
		Enable => CW10,
		OutputA => signalMuxBanco,
		OutputB => signalEntradaRAM
	);

	Inst_RAM_16x10: RAM_16x10 PORT MAP(
		Address => AddressRAM,
		DataIn => signalEntradaRAM,
		Enable => CW4,
		CLK => CLK,
		DataOut => signalSalRAM
	);
	
	Inst_Deco1to2: Deco1to2 PORT MAP(
		Input => signalSalRAM,
		Enable => CW6,
		OutputA => signalDatoBanco,
		OutputB => signalRegInst
	);
	
	Inst_Mux2_4bits: Mux2_4bits PORT MAP(
		A => signalDatoBanco,
		B => signalMuxBanco,
		Sel => CW9,
		Z => signalEntradaBanco
	);
	
	Inst_Mux2_4bits_Banco: Mux2_4bits PORT MAP(
		A => signalSalBancotoRegA,
		B => signalSaltoInm,
		Sel => CW8,
		Z => signalSaltoRegA
	);
	
	Inst_DataPath: DataPath PORT MAP(
		InRegA => signalSaltoRegA,
		InRegB => signalSalBancotoRegB,
		COP => signalSalRegInst(2 downto 0),
		CLK => CLK,
		RESET => RESET,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		SalALU => signalSalALU,
		SalRegA => SalidaRegA,
		SalRegB => SalidaRegB,
		SalFZ => signalSalFZ
	);
	
	COP <= signalSalRegInst(2 downto 0);
	
	SalFZ<=signalSalFZ;
	
	Inst_Deco2to4: Deco2to4 PORT MAP(
		Input => signalSalRegInst(6 downto 3),
		Enable => CW7,
		OutputA => AddressRAMOUT,
		OutputB => signalSaltoBanco,
		OutputC => signalSaltoInm
	);
	
	Inst_Banco_Registros: Banco_Registros PORT MAP(
		DirA => signalSaltoBanco(2 downto 0),
		DirB => signalSalRegInst(9 downto 7),
		Data_IN => signalEntradaBanco,
		CLK => CLK,
		RESET => RESET,
		CW3 => CW3,
		SalDirA => signalSalBancotoRegA,
		SalDirB => signalSalBancotoRegB
	);

end Behavioral;

