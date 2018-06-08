----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    08:54:15 12/01/2017 
-- Design Name: 
-- Module Name:    RAM_16x4 - Behavioral 
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

entity RAM_16x4 is
    Port ( DataIn : in  STD_LOGIC_VECTOR (3 downto 0);
           WE : in  STD_LOGIC;
           Address : in  STD_LOGIC_VECTOR (3 downto 0);
           DataOut : out  STD_LOGIC_VECTOR (3 downto 0);
           CLK : in  STD_LOGIC);
end RAM_16x4;

architecture Behavioral of RAM_16x4 is

type ram_type is array(15 downto 0)of std_logic_vector(3 downto 0);
signal RAM :ram_type:=(
	0=>"0101",
	1=>"1111",
	2=>"1110",
	3=>"1110",
	4=>"1110",
	5=>"0000",
	6=>"0001",
	7=>"0010",
	8=>"0101",
	9=>"1111",
	10=>"0000",
	11=>"0000",
	12=>"0000",
	13=>"0000",
	14=>"0000",
	15=>"0000"
	);



begin
	process(Clk)
	begin
		if rising_edge(Clk)then
			--Operación de LECTURA/ESCRITURA síncrona
			if WE='1' then
				RAM(to_integer(unsigned(Address)))<=DataIn;--Conversión en dos pasos de --std_logic_vectora --integer(numeric_std) DataOut <=DataIn; --El dato que se lee, es el mismo que se escribe
			else
				--Operación de SOLO LECTURA
				DataOut <=RAM(to_integer(unsigned(Address))); --Valor leído en Address
			end if;
		end if;
	end process;
end Behavioral;

