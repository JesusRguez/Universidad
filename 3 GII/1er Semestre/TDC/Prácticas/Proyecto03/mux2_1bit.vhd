----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:27:06 10/11/2017 
-- Design Name: 
-- Module Name:    mux2_1bit - Behavioral 
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

entity mux2_1bit is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Sel : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end mux2_1bit;

architecture Behavioral of mux2_1bit is

begin
	-- Descripción del MUX mediante sentencia concurrente condicional
	-- Y<=A when Sel = '0' else B;
	-- Descripción de los procesos
	process (A, B, Sel) --Esta es la lista de sensibilidad y es la lista de todas las señales que se leen en el proceso.
	begin
		if Sel='0' then
			Y<=A;
		else
			Y<=B;
		end if;
	end process;
end Behavioral;

