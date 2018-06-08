
-- VHDL Instantiation Created from source file DataPath.vhd -- 09:26:38 01/22/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT DataPath
	PORT(
		DataBus : IN std_logic_vector(3 downto 0);
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

	Inst_DataPath: DataPath PORT MAP(
		DataBus => ,
		COP => ,
		CLK => ,
		RESET => ,
		CW0 => ,
		CW1 => ,
		CW2 => ,
		SalALU => ,
		SalRegA => ,
		SalRegB => ,
		SalFZ => 
	);


