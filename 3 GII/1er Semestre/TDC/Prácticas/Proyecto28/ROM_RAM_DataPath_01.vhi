
-- VHDL Instantiation Created from source file ROM_RAM_DataPath_01.vhd -- 11:13:51 12/13/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT ROM_RAM_DataPath_01
	PORT(
		AddressROM : IN std_logic_vector(2 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		CW3 : IN std_logic;
		CW4 : IN std_logic;
		CW5 : IN std_logic;
		Sel_ALU : IN std_logic_vector(1 downto 0);          
		Instruction : OUT std_logic_vector(7 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0);
		SalCOP : OUT std_logic_vector(1 downto 0);
		DataBus : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;

	Inst_ROM_RAM_DataPath_01: ROM_RAM_DataPath_01 PORT MAP(
		AddressROM => ,
		CLK => ,
		RESET => ,
		CW0 => ,
		CW1 => ,
		CW2 => ,
		CW3 => ,
		CW4 => ,
		CW5 => ,
		Sel_ALU => ,
		Instruction => ,
		AddressRAM => ,
		SalCOP => ,
		DataBus => ,
		SalRegA => ,
		SalRegB => ,
		SalFZ => 
	);


