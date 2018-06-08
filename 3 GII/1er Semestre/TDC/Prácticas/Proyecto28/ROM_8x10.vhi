
-- VHDL Instantiation Created from source file ROM_8x10.vhd -- 10:30:15 12/13/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT ROM_8x10
	PORT(
		Address : IN std_logic_vector(2 downto 0);
		CLK : IN std_logic;
		Enable : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;

	Inst_ROM_8x10: ROM_8x10 PORT MAP(
		Address => ,
		CLK => ,
		Enable => ,
		DataOut => 
	);


