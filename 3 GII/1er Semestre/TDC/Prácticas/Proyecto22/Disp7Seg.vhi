
-- VHDL Instantiation Created from source file Disp7Seg.vhd -- 10:24:44 11/22/2017
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Disp7Seg
	PORT(
		Hex : IN std_logic_vector(3 downto 0);
		Select_Disp : IN std_logic_vector(1 downto 0);          
		Seg : OUT std_logic_vector(6 downto 0);
		Anode : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Disp7Seg: Disp7Seg PORT MAP(
		Hex => ,
		Select_Disp => ,
		Seg => ,
		Anode => 
	);


