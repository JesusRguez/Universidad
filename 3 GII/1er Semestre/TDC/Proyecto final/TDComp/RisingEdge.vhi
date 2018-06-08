
-- VHDL Instantiation Created from source file RisingEdge.vhd -- 12:24:17 01/25/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT RisingEdge
	PORT(
		RESET : IN std_logic;
		PUSH : IN std_logic;
		CLK : IN std_logic;          
		Pulse : OUT std_logic
		);
	END COMPONENT;

	Inst_RisingEdge: RisingEdge PORT MAP(
		RESET => ,
		PUSH => ,
		CLK => ,
		Pulse => 
	);


