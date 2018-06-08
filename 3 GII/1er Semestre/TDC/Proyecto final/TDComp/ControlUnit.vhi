
-- VHDL Instantiation Created from source file ControlUnit.vhd -- 11:43:56 01/25/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT ControlUnit
	PORT(
		Push : IN std_logic;
		RESET : IN std_logic;
		CLK : IN std_logic;
		FZ : IN std_logic;
		COP : IN std_logic_vector(2 downto 0);          
		ControlWord : OUT std_logic_vector(14 downto 0)
		);
	END COMPONENT;

	Inst_ControlUnit: ControlUnit PORT MAP(
		Push => ,
		RESET => ,
		CLK => ,
		FZ => ,
		COP => ,
		ControlWord => 
	);


