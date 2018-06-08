----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    12:53:25 01/23/2018 
-- Design Name: 
-- Module Name:    Inc_4bits - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Inc_4bits is
	Port ( Value : in  STD_LOGIC_VECTOR (3 downto 0);
           Value_Inc : out  STD_LOGIC_VECTOR (3 downto 0));
end Inc_4bits;

architecture Behavioral of Inc_4bits is

begin

	Value_Inc<=std_logic_vector(unsigned(Value)+1);

end Behavioral;

