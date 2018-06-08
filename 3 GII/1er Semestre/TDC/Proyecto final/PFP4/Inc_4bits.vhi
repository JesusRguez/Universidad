
-- VHDL Instantiation Created from source file Inc_4bits.vhd -- 13:00:05 01/23/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Inc_4bits
	PORT(
		Value : IN std_logic_vector(3 downto 0);          
		Value_Inc : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Inc_4bits: Inc_4bits PORT MAP(
		Value => ,
		Value_Inc => 
	);


