
-- VHDL Instantiation Created from source file ALU_4bits.vhd -- 11:45:27 11/22/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT ALU_4bits
	PORT(
		OPE_A : IN std_logic_vector(3 downto 0);
		OPE_B : IN std_logic_vector(3 downto 0);
		SEL_ALU : IN std_logic_vector(1 downto 0);          
		Sal_ALU : OUT std_logic_vector(3 downto 0);
		SalFZ : OUT std_logic
		);
	END COMPONENT;

	Inst_ALU_4bits: ALU_4bits PORT MAP(
		OPE_A => ,
		OPE_B => ,
		SEL_ALU => ,
		Sal_ALU => ,
		SalFZ => 
	);


