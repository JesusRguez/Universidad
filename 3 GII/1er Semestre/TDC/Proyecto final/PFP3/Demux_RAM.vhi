
-- VHDL Instantiation Created from source file Demux_RAM.vhd -- 11:22:47 01/23/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Demux_RAM
	PORT(
		Input : IN std_logic_vector(3 downto 0);
		Enable : IN std_logic;          
		OutputA : OUT std_logic_vector(3 downto 0);
		OutputB : OUT std_logic_vector(9 downto 0)
		);
	END COMPONENT;

	Inst_Demux_RAM: Demux_RAM PORT MAP(
		Input => ,
		Enable => ,
		OutputA => ,
		OutputB => 
	);


