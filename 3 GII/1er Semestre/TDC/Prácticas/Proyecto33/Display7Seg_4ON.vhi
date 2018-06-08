
-- VHDL Instantiation Created from source file Display7Seg_4ON.vhd -- 11:50:51 01/17/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Display7Seg_4ON
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;
		Dato1 : IN std_logic_vector(3 downto 0);
		Dato2 : IN std_logic_vector(3 downto 0);
		Dato3 : IN std_logic_vector(3 downto 0);
		Dato4 : IN std_logic_vector(3 downto 0);          
		Anodo : OUT std_logic_vector(3 downto 0);
		Catodo : OUT std_logic_vector(6 downto 0)
		);
	END COMPONENT;

	Inst_Display7Seg_4ON: Display7Seg_4ON PORT MAP(
		CLK => ,
		RESET => ,
		Dato1 => ,
		Dato2 => ,
		Dato3 => ,
		Dato4 => ,
		Anodo => ,
		Catodo => 
	);


