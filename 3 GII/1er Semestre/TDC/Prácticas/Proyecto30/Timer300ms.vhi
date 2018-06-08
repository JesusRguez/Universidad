
-- VHDL Instantiation Created from source file Timer300ms.vhd -- 12:00:21 01/10/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Timer300ms
	PORT(
		Enable : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		End300ms : OUT std_logic
		);
	END COMPONENT;

	Inst_Timer300ms: Timer300ms PORT MAP(
		Enable => ,
		CLK => ,
		RESET => ,
		End300ms => 
	);


