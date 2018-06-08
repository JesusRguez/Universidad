----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:10:15 10/18/2017 
-- Design Name: 
-- Module Name:    Mux_Disp_LED - Behavioral 
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

entity Mux_Disp_LED is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           Sel : in  STD_LOGIC;
           Seg : out  STD_LOGIC_VECTOR (6 downto 0);
           LED : out  STD_LOGIC_VECTOR (3 downto 0);
           Anode : out  STD_LOGIC_VECTOR (3 downto 0));
end Mux_Disp_LED;

architecture Structural of Mux_Disp_LED is

--LISTA DE COMPONENTES
COMPONENT Mux2_4bits
	PORT(
		A : IN std_logic_vector(3 downto 0);
		B : IN std_logic_vector(3 downto 0);
		Sel : IN std_logic;          
		Z : OUT std_logic_vector(3 downto 0)
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
--FIN LISTA DE COMPONENTES

--LISTA DE SEÑALES
signal signal_Z : std_logic_vector(3 downto 0);

begin
	Inst_Mux2_4bits: Mux2_4bits PORT MAP(
		A => A,
		B => B,
		Sel => Sel,
		Z => Signal_Z
	);
	
	Inst_Disp7Seg: Disp7Seg PORT MAP(
		Hex => signal_Z,
		Select_Disp => "00",
		Seg => Seg,
		Anode => Anode
	);
	
	LED<=signal_Z;	
	
end Structural;