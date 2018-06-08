
-- VHDL Instantiation Created from source file RAM_16x10.vhd -- 19:39:22 01/21/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT RAM_16x10
	PORT(
		Address : IN std_logic_vector(9 downto 0);
		DataIn : IN std_logic_vector(9 downto 0);
		Enable : IN std_logic;
		CLK : IN std_logic;          
		DataOut : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;

	Inst_RAM_16x10: RAM_16x10 PORT MAP(
		Address => ,
		DataIn => ,
		Enable => ,
		CLK => ,
		DataOut => 
	);


