
-- VHDL Instantiation Created from source file Banco_Registros.vhd -- 09:26:59 01/22/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Banco_Registros
	PORT(
		DirA : IN std_logic_vector(2 downto 0);
		DirB : IN std_logic_vector(2 downto 0);
		Data_IN : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW3 : IN std_logic;          
		SalDirA : OUT std_logic_vector(3 downto 0);
		SalDirB : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Banco_Registros: Banco_Registros PORT MAP(
		DirA => ,
		DirB => ,
		Data_IN => ,
		CLK => ,
		RESET => ,
		CW3 => ,
		SalDirA => ,
		SalDirB => 
	);


