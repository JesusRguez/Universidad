----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Jesús Rodríguez Heras
-- 
-- Create Date:    09:12:08 10/20/2017 
-- Design Name: 
-- Module Name:    ALU_1bit - Structural 
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

entity ALU_1bit is
    Port ( A : in  STD_LOGIC;
			  B : in  STD_LOGIC;
           Carry_In : in  STD_LOGIC;
           Sel_Ope : in  STD_LOGIC_VECTOR (1 downto 0);
           Carry_Out : out  STD_LOGIC;
           Result : out  STD_LOGIC);
end ALU_1bit;

architecture Structural of ALU_1bit is
-- List of components
COMPONENT add_1bit
	PORT(
		A : IN std_logic;
		B : IN std_logic;
		Cin : IN std_logic;          
		Cout : OUT std_logic;
		Result : OUT std_logic
		);
	END COMPONENT;
	
COMPONENT and_gate
	PORT(
		a : IN std_logic;
		b : IN std_logic;          
		c : OUT std_logic
		);
	END COMPONENT;
	
COMPONENT xnor_gate
	PORT(
		a : IN std_logic;
		b : IN std_logic;          
		c : OUT std_logic
		);
	END COMPONENT;
	
-- List of signals
signal SignalPaso: std_logic;
signal SignalXnor: std_logic;
signal SignalAnd: std_logic;
signal SignalSuma: std_logic;
--signal SignalCout: std_logic;

begin
	Inst_add_1bit: add_1bit PORT MAP(
		A => A,
		B => B,
		Cin => Carry_In,
		Cout => Carry_Out,
		Result => SignalSuma
	);
	
	Inst_and_gate: and_gate PORT MAP(
		a => A,
		b => B,
		c => SignalAnd
	);
	
	Inst_xnor_gate: xnor_gate PORT MAP(
		a => A,
		b => B,
		c => SignalXnor
	);
	
	SignalPaso<=A;
	
	process(SignalSuma, SignalAnd, SignalXnor, SignalPaso, Sel_Ope)
		begin
			case Sel_Ope is
				when "00"=>Result<=SignalSuma;
				when "01"=>Result<=SignalAnd;
				when "10"=>Result<=SignalXnor;
				when "11"=>Result<=SignalPaso;
				when others=>Result<='0';
			end case;
	end process;
	
end Structural;

