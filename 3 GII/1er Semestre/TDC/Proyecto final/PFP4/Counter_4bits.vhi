
-- VHDL Instantiation Created from source file Counter_4bits.vhd -- 13:38:12 01/23/2018
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT Counter_4bits
	PORT(
		AddressJump : IN std_logic_vector(3 downto 0);
		CLK : IN std_logic;
		RESET : IN std_logic;
		CW11 : IN std_logic;
		CW12 : IN std_logic;
		CW13 : IN std_logic;          
		PC_RAM : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;

	Inst_Counter_4bits: Counter_4bits PORT MAP(
		AddressJump => ,
		CLK => ,
		RESET => ,
		CW11 => ,
		CW12 => ,
		CW13 => ,
		PC_RAM => 
	);


