----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:03:45 01/21/2018 
-- Design Name: 
-- Module Name:    RAM_16x10 - Behavioral 
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

entity RAM_16x10 is
    Port ( Address : in  STD_LOGIC_VECTOR (3 downto 0);
			  DataIn : in  STD_LOGIC_VECTOR (9 downto 0);
           Enable : in  STD_LOGIC;
			  CLK : in  STD_LOGIC;
           DataOut : out  STD_LOGIC_VECTOR (9 downto 0));
end RAM_16x10;

architecture Behavioral of RAM_16x10 is

type ram_type is array(15 downto 0)of std_logic_vector(9 downto 0);
signal RAM :ram_type:=(
	0=>"0101000000",
	1=>"1111000000",
	2=>"1110000000",
	3=>"1110000000",
	4=>"1110000000",
	5=>"0000000000",
	6=>"0001000000",
	7=>"0010000000",
	8=>"0101000000",
	9=>"1111000000",
	10=>"0000000000",
	11=>"0000000000",
	12=>"0000000000",
	13=>"0000000000",
	14=>"0000000000",
	15=>"0000000000"
	);

begin
	process(CLK)
	begin
		if rising_edge(Clk)then
			--Operación de LECTURA/ESCRITURA síncrona
			if Enable='1' then
				RAM(to_integer(unsigned(Address)))<=DataIn;--Conversión en dos pasos de --std_logic_vectora --integer(numeric_std) DataOut <=DataIn; --El dato que se lee, es el mismo que se escribe
			else
				--Operación de SOLO LECTURA
				DataOut <=RAM(to_integer(unsigned(Address))); --Valor leído en Address
			end if;
		end if;
	end process;
end Behavioral;

