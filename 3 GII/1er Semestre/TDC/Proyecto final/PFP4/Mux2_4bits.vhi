
-- VHDL Instantiation Created from source file Mux2_4bits.vhd -- 13:01:02 01/23/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Mux2_4bits
	PORT(
		A : IN std_logic_vector(3 downto 0);
		B : IN std_logic_vector(3 downto 0);
		Sel : IN std_logic;          
		Z : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Mux2_4bits: Mux2_4bits PORT MAP(
		A => ,
		B => ,
		Sel => ,
		Z => 
	);


