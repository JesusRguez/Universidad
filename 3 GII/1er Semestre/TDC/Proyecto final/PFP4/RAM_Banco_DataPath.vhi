
-- VHDL Instantiation Created from source file RAM_Banco_DataPath.vhd -- 13:24:36 01/23/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

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
		AddressRAMOUT : OUT std_logic_vector(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_RAM_Banco_DataPath: RAM_Banco_DataPath PORT MAP(
		AddressRAM => ,
		CLK => ,
		RESET => ,
		CW0 => ,
		CW1 => ,
		CW2 => ,
		CW3 => ,
		CW4 => ,
		CW5 => ,
		CW6 => ,
		CW7 => ,
		CW8 => ,
		CW9 => ,
		CW10 => ,
		SalFZ => ,
		AddressRAMOUT => ,
		SalidaRegA => ,
		SalidaRegB => 
	);


