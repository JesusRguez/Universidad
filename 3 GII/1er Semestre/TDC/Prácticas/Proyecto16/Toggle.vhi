
-- VHDL Instantiation Created from source file Toggle.vhd -- 09:22:44 11/10/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Toggle
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		ENABLE : IN std_logic;          
		Q : OUT std_logic
		);
	END COMPONENT;

	Inst_Toggle: Toggle PORT MAP(
		CLK => ,
		RESET => ,
		ENABLE => ,
		Q => 
	);


