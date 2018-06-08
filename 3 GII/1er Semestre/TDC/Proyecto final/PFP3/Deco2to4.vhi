
-- VHDL Instantiation Created from source file Deco2to4.vhd -- 10:15:59 01/22/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Deco2to4
	PORT(
		Input : IN std_logic_vector(3 downto 0);
		Enable : IN std_logic_vector(1 downto 0);          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(3 downto 0);
		OutputC : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Deco2to4: Deco2to4 PORT MAP(
		Input => ,
		Enable => ,
		OutputA => ,
		OutputB => ,
		OutputC => 
	);


