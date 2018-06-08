
-- VHDL Instantiation Created from source file Counter_Nbits.vhd -- 11:00:27 11/15/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Counter_Nbits
	PORT(
		ENABLE : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		Q : OUT std_logic_vector(7 downto 0)
		);
	END COMPONENT;

	Inst_Counter_Nbits: Counter_Nbits PORT MAP(
		ENABLE => ,
		CLK => ,
		RESET => ,
		Q => 
	);


