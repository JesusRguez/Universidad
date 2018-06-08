
-- VHDL Instantiation Created from source file PC_RAM_BancoDataPath.vhd -- 11:43:22 01/25/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT PC_RAM_BancoDataPath
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
		CW7 : IN std_logic_vector(1 downto 0);
		CW8 : IN std_logic;
		CW9 : IN std_logic;
		CW10 : IN std_logic;
		CW11 : IN std_logic;
		CW12 : IN std_logic;
		CW13 : IN std_logic;          
		SalFZ : OUT std_logic;
		COP : OUT std_logic_vector(2 downto 0);
		SalidaRegA : OUT std_logic_vector(3 downto 0);
		SalidaRegB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_PC_RAM_BancoDataPath: PC_RAM_BancoDataPath PORT MAP(
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
		CW11 => ,
		CW12 => ,
		CW13 => ,
		SalFZ => ,
		COP => ,
		SalidaRegA => ,
		SalidaRegB => 
	);


