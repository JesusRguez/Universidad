
-- VHDL Instantiation Created from source file TDComp.vhd -- 12:32:06 01/25/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT TDComp
	PORT(
		Push : IN std_logic;
		RESET : IN std_logic;
		CLK : IN std_logic;          
		FZ : OUT std_logic;
		COP : OUT std_logic_vector(2 downto 0);
		Instruction : OUT std_logic_vector(9 downto 0);
		SalidaALU : OUT std_logic_vector(3 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0);
		AddressRAM : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_TDComp: TDComp PORT MAP(
		Push => ,
		RESET => ,
		CLK => ,
		FZ => ,
		COP => ,
		Instruction => ,
		SalidaALU => ,
		SalidaRegA => ,
		SalidaRegB => ,
		AddressRAM => 
	);


