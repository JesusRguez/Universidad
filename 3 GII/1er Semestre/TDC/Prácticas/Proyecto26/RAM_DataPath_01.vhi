
-- VHDL Instantiation Created from source file RAM_DataPath_01.vhd -- 09:43:13 12/01/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

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

	Inst_RAM_DataPath_01: RAM_DataPath_01 PORT MAP(
		AddressRam => ,
		CW0 => ,
		CW1 => ,
		CW2 => ,
		CW3 => ,
		CLK => ,
		RESET => ,
		Sel_ALU => ,
		DataBus => ,
		SalRegA => ,
		SalRegB => ,
		SalFZ => ,
		SalALU => 
	);


