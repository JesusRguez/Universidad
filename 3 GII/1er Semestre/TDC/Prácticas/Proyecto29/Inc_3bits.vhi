
-- VHDL Instantiation Created from source file Inc_3bits.vhd -- 09:37:27 12/15/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Inc_3bits
	PORT(
		Value : IN std_logic_vector(2 downto 0);       
		Value_Inc : INOUT std_logic_vector(2 downto 0)
		);
	END COMPONENT;

	Inst_Inc_3bits: Inc_3bits PORT MAP(
		Value => ,
		Value_Inc => 
	);


