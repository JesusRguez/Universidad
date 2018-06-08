----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:13:01 11/22/2017 
-- Design Name: 
-- Module Name:    Display7Seg_4ON - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Display7Seg_4ON is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Dato1 : in  STD_LOGIC_VECTOR (3 downto 0);
           Dato2 : in  STD_LOGIC_VECTOR (3 downto 0);
           Dato3 : in  STD_LOGIC_VECTOR (3 downto 0);
           Dato4 : in  STD_LOGIC_VECTOR (3 downto 0);
           Anodo : out  STD_LOGIC_VECTOR (3 downto 0);
           Catodo : out  STD_LOGIC_VECTOR (6 downto 0));
			  
end Display7Seg_4ON;

architecture Behavioral of Display7Seg_4ON is

	COMPONENT CLK_1KHz
	PORT(
		CLK : IN std_logic;
		RESET : IN std_logic;          
		Out_1KHz : OUT std_logic
		);
	END COMPONENT;
	
	COMPONENT Counter_2bits
	PORT(
		ENABLE : IN std_logic;
		CLK : IN std_logic;
		RESET : IN std_logic;          
		Q : OUT std_logic_vector(1 downto 0)
		);
	END COMPONENT;
	
	COMPONENT Disp7Seg
	PORT(
		Hex : IN std_logic_vector(3 downto 0);
		Select_Disp : IN std_logic_vector(1 downto 0);          
		Seg : OUT std_logic_vector(6 downto 0);
		Anode : OUT std_logic_vector(3 downto 0)
		);
	END COMPONENT;
	
	signal div_1kHz:std_logic;
	signal salida_cont:std_logic_vector(1 downto 0);
	signal salida_mux:std_logic_vector(3 downto 0);

begin

	Inst_CLK_1KHz: CLK_1KHz PORT MAP(
		CLK => CLK,
		RESET => RESET,
		Out_1KHz => div_1kHz
	);
	
	Inst_Counter_2bits: Counter_2bits PORT MAP(
		ENABLE => div_1kHz,
		CLK => CLK,
		RESET => RESET,
		Q => salida_cont
	);
	
	Inst_Disp7Seg: Disp7Seg PORT MAP(
		Hex => salida_mux,
		Select_Disp => salida_cont,
		Seg => Catodo,
		Anode => Anodo
	);
	
	process(Dato1,Dato2,Dato3,Dato4,salida_cont)
		begin
			case salida_cont is
				when "00"=>salida_mux<=Dato1;
				when "01"=>salida_mux<=Dato2;
				when "10"=>salida_mux<=Dato3;
				when "11"=>salida_mux<=Dato4;
				when others =>salida_mux<="0000";
			end case;
	end process;

end Behavioral;

