
-- VHDL Instantiation Created from source file MicroArq_DidaComp.vhd -- 10:52:23 12/20/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT MicroArq_DidaComp
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW0 : IN std_logic;
		CW1 : IN std_logic;
		CW2 : IN std_logic;
		CW3 : IN std_logic;
		CW4 : IN std_logic;
		CW5 : IN std_logic;
		CW6 : IN std_logic;
		CW7 : IN std_logic;
		SelALU : IN std_logic_vector(1 downto 0);          
		RegInst : OUT std_logic_vector(7 downto 0);
		AddressROM : OUT std_logic_vector(3 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		DataBus : OUT std_logic_vector(3 downto 0);
		COP : OUT std_logic_vector(1 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;

	Inst_MicroArq_DidaComp: MicroArq_DidaComp PORT MAP(
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
		SelALU => ,
		RegInst => ,
		AddressROM => ,
		AddressRAM => ,
		SalRegA => ,
		SalRegB => ,
		DataBus => ,
		COP => ,
		SalFZ => 
	);


