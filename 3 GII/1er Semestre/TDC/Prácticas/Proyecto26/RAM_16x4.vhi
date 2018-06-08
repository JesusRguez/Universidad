
-- VHDL Instantiation Created from source file RAM_16x4.vhd -- 09:21:04 12/01/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT RAM_16x4
	PORT(
		DataIn : IN std_logic_vector(3 downto 0);
		WE : IN std_logic;
		Address : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;          
		DataOut : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_RAM_16x4: RAM_16x4 PORT MAP(
		DataIn => ,
		WE => ,
		Address => ,
		DataOut => ,
		CLK => 
	);


