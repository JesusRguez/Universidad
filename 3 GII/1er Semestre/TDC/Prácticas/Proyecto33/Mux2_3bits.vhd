----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:14:38 10/18/2017 
-- Design Name: 
-- Module Name:    Mux2_3bits - Behavioral 
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

entity Mux2_3bits is
    Port ( A : in  STD_LOGIC_VECTOR (2 downto 0);
           B : in  STD_LOGIC_VECTOR (2 downto 0);
           Sel : in  STD_LOGIC;
           Z : out  STD_LOGIC_VECTOR (2 downto 0));
end Mux2_3bits;

architecture Behavioral of Mux2_3bits is

begin
	process(A,B,Sel)
		begin
			case Sel is
				when '0'=>Z<=A;
				when '1'=>Z<=B;
				when others =>Z<="000";
			end case;
	end process;
end Behavioral;

