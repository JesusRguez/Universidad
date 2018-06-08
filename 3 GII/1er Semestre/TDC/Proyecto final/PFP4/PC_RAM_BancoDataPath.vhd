----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:50:33 01/23/2018 
-- Design Name: 
-- Module Name:    PC_RAM_BancoDataPath - Behavioral 
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

entity PC_RAM_BancoDataPath is
Port ( 
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
			  CW11 : in  STD_LOGIC;--Enable de PC
			  CW12 : in  STD_LOGIC;--Enable del muxpc
			  CW13 : in  STD_LOGIC;--Enable del mux del contador y la direccion de la RAM
			  SalFZ : out  STD_LOGIC;
			  COP : out  STD_LOGIC_VECTOR(2 downto 0);
			  SalidaRegA : OUT std_logic_vector(3 downto 0);
			  SalidaRegB : OUT std_logic_vector(3 downto 0));
end PC_RAM_BancoDataPath;

architecture Behavioral of PC_RAM_BancoDataPath is

	COMPONENT Counter_4bits
	PORT(
		AddressJump : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW11 : IN std_logic;
		CW12 : IN std_logic;
		CW13 : IN std_logic;          
		PC_RAM : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	COMPONENT RAM_Banco_DataPath
	PORT(
		AddressRAM : IN std_logic_vector(3 downto 0);
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
		SalFZ : OUT std_logic;
		COP : out  STD_LOGIC_VECTOR(2 downto 0);
		AddressRAMOUT : OUT std_logic_vector(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal signalAddressJump:std_logic_vector(3 downto 0);
	signal signal_PC_RAM:std_logic_vector(3 downto 0);

begin
	
	Inst_Counter_4bits: Counter_4bits PORT MAP(
		AddressJump => signalAddressJump,
		CLK => CLK,
		RESET => RESET,
		CW11 => CW11,
		CW12 => CW12,
		CW13 => CW13,
		PC_RAM => signal_PC_RAM
	);
	
	Inst_RAM_Banco_DataPath: RAM_Banco_DataPath PORT MAP(
		AddressRAM => signal_PC_RAM,
		CLK => CLK,
		RESET => RESET,
		CW0 => CW0,
		CW1 => CW1,
		CW2 => CW2,
		CW3 => CW3,
		CW4 => CW4,
		CW5 => CW5,
		CW6 => CW6,
		CW7 => CW7,
		CW8 => CW8,
		CW9 => CW9,
		CW10 => CW10,
		SalFZ => SalFZ,
		COP => COP,
		AddressRAMOUT => signalAddressJump,
		SalidaRegA => SalidaRegA,
		SalidaRegB => SalidaRegB
	);

end Behavioral;

