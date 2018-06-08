
-- VHDL Instantiation Created from source file DidaComp.vhd -- 11:50:36 01/17/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT DidaComp
	PORT(
		Push : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		AddressRAM : OUT std_logic_vector(3 downto 0);
		AddressROM : OUT std_logic_vector(3 downto 0);
		SalRegA : OUT std_logic_vector(3 downto 0);
		SalRegB : OUT std_logic_vector(3 downto 0);
		COP : OUT std_logic_vector(1 downto 0);
		Instruction : OUT std_logic_vector(7 downto 0);
		FZ : OUT std_logic
		);
	END COMPONENT;

	Inst_DidaComp: DidaComp PORT MAP(
		Push => ,
		CLK => ,
		RESET => ,
		AddressRAM => ,
		AddressROM => ,
		SalRegA => ,
		SalRegB => ,
		COP => ,
		Instruction => ,
		FZ => 
	);


