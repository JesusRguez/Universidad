
-- VHDL Instantiation Created from source file ALU.vhd -- 12:58:54 01/21/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT ALU
	PORT(
		OPE_A : IN std_logic_vector(3 downto 0);
		OPE_B : IN std_logic_vector(3 downto 0);
		COP : IN std_logic_vector(2 downto 0);          
		SalALU : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;

	Inst_ALU: ALU PORT MAP(
		OPE_A => ,
		OPE_B => ,
		COP => ,
		SalALU => ,
		SalFZ => 
	);


