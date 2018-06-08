
-- VHDL Instantiation Created from source file Deco1to2.vhd -- 09:44:10 01/22/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Deco1to2
	PORT(
		Input : IN std_logic_vector(9 downto 0);
		Enable : IN std_logic;          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;

	Inst_Deco1to2: Deco1to2 PORT MAP(
		Input => ,
		Enable => ,
		OutputA => ,
		OutputB => 
	);


