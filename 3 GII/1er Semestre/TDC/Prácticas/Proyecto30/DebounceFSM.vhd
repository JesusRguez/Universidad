----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    11:31:16 01/10/2018 
-- Design Name: 
-- Module Name:    DebounceFSM - Behavioral 
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

entity DebounceFSM is
    Port ( CLK : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           Flag_Timer : in  STD_LOGIC;
           Push : in  STD_LOGIC;
           EnableTimer : out  STD_LOGIC;
           FilteredPush : out  STD_LOGIC);
end DebounceFSM;

architecture Behavioral of DebounceFSM is

type RisingEdge_States is(inic,S0,S01,espera);
signal Next_State:RisingEdge_States ;

begin

	Process(RESET,CLK)
	begin
		if RESET ='1' then
			Next_State<=inic;--INICIO CON RESET
			elsif rising_edge(CLK) then
			case Next_State is
				when inic =>if Push='0' then
					Next_State <=S0;--llega "0-"
				end if;
				when S0=>if Push ='1' then
					Next_State <=S01;--llega "01"
				end if;
				when S01 =>
					Next_State <=espera;
				when espera =>
					if Flag_Timer='1' then
						Next_State<=inic;
					end if;
				when others=>Next_State <=inic;
			end case;
		end if;
	end process;
	
	EnableTimer <= '1' when Next_State = S01 else '0';
	FilteredPush <= '1' when Next_State = S01 else '0';
	

end Behavioral;

