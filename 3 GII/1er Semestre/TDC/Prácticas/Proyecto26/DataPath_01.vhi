
-- VHDL Instantiation Created from source file DataPath_01.vhd -- 09:21:26 12/01/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

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

	Inst_DataPath_01: DataPath_01 PORT MAP(
		DataBus => ,
		SEL_ALU => ,
		CLK => ,
		CW0 => ,
		CW1 => ,
		CW2 => ,
		RESET => ,
		SalALU => ,
		SalREGA => ,
		SalREGB => ,
		SalFZ => 
	);


