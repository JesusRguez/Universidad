----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    09:32:46 12/15/2017 
-- Design Name: 
-- Module Name:    Reg_3bits - Behavioral 
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

entity Reg_3bits is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           DataIn : in  STD_LOGIC_VECTOR (2 downto 0);
           ENABLE : in  STD_LOGIC;
           DataOut : out  STD_LOGIC_VECTOR (2 downto 0));
end Reg_3bits;

architecture Behavioral of Reg_3bits is

begin

	process(CLK, RESET)
	begin
		if RESET='1' then
			DataOut<="000";
		elsif rising_edge(CLK) then
			if ENABLE='1' then
				DataOut<=DataIn;
			end if;
		end if;
	end process;

end Behavioral;

