
-- VHDL Instantiation Created from source file DebounceFSM.vhd -- 11:59:48 01/10/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT DebounceFSM
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		Flag_Timer : IN std_logic;
		Push : IN std_logic;          
		EnableTimer : OUT std_logic;
		FilteredPush : OUT std_logic
		);
	END COMPONENT;

	Inst_DebounceFSM: DebounceFSM PORT MAP(
		CLK => ,
		RESET => ,
		Flag_Timer => ,
		Push => ,
		EnableTimer => ,
		FilteredPush => 
	);


