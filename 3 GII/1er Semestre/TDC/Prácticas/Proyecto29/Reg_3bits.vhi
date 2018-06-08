
-- VHDL Instantiation Created from source file Reg_3bits.vhd -- 09:37:02 12/15/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Reg_3bits
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		DataIn : IN std_logic_vector(2 downto 0);
		ENABLE : IN std_logic;          
		DataOut : OUT std_logic_vector(2 downto 0)
		);
	END COMPONENT;

	Inst_Reg_3bits: Reg_3bits PORT MAP(
		CLK => ,
		RESET => ,
		DataIn => ,
		ENABLE => ,
		DataOut => 
	);


