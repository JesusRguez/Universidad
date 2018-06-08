----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:21:25 01/25/2018 
-- Design Name: 
-- Module Name:    ControlUnit - Behavioral 
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

entity ControlUnit is
    Port ( Push : in  STD_LOGIC;
           RESET : in  STD_LOGIC;
           CLK : in  STD_LOGIC;
           FZ : in  STD_LOGIC;
			  COP : in  STD_LOGIC_VECTOR(2 downto 0);
           ControlWord : out  STD_LOGIC_VECTOR (14 downto 0));
end ControlUnit;

architecture Behavioral of ControlUnit is

------------------------------------------------------
--DEFINITION of STATES
-------------------------------------------------------
type States_FSM is(Idle,LoadInst,Deco,LoadA,LoadReg,StRAM,LoadRARB,AaddB,AsubB,LoadRegI,AincB,AdecB,BEQ);
signal Next_State:States_FSM;
------------------------------------------------------
--DEFINITION of the OUTPUTS for each STATE
-------------------------------------------------------
constant Outputs_Idle:std_logic_Vector(14 downto 0):="000000000000000";
constant Outputs_LoadInst:std_logic_Vector(14 downto 0):="111000000100000";
constant Outputs_Deco:std_logic_vector(14 downto 0):="000000000000000";
constant Outputs_LoadA:std_logic_Vector(14 downto 0):="000000001001000";
constant Outputs_LoadReg:std_logic_Vector(14 downto 0):="000000000000001";
constant Outputs_StRAM:std_logic_vector(14 downto 0):="000000000010000";
constant Outputs_LoadRARB:std_logic_Vector(14 downto 0):="000000010000011";
constant Outputs_AaddB:std_logic_vector(14 downto 0):="000110000001100";
constant Outputs_AsubB:std_logic_vector(14 downto 0):="000110000001100";
constant Outputs_LoadRegI:std_logic_vector(14 downto 0):="000001100000011";
constant Outputs_AincB:std_logic_vector(14 downto 0):="000110000001100";
constant Outputs_AdecB:std_logic_vector(14 downto 0):="000110000001100";
constant Outputs_BEQ:std_logic_vector(14 downto 0):="110000000000000";
-----------------------------------------------------------------

begin

	process(CLK,RESET)
	begin
		if RESET ='1' then
			Next_State<=Idle;--INICIO si RESET
		elsif rising_edge(CLK) then
			case Next_State is
				--State "Idle"
				when Idle=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "LoadInst"
				when LoadInst=>
					if(Push='1')then
						Next_State<=Deco;
					end if;
				--State "Deco"
				when Deco=>
					if(Push='1')then
						if(COP="110" and FZ='0')then
							Next_State<=LoadInst;
						end if;
						if(COP="110" and FZ='1')then
							Next_State<=BEQ;
						end if;
						if(COP="010" or COP="011")then
							Next_State<=LoadRARB;
						end if;
						if(COP="100" or COP="101")then
							Next_State<=LoadRegI;
						end if;
						if(COP="000")then
							Next_State<=LoadA;
						end if;
						if(COP="001")then
							Next_State<=LoadReg;
						end if;
					end if;
				--State "LoadA"
				when LoadA=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "LoadReg"
				when LoadReg=>
					if(Push='1')then
						Next_State<=StRAM;
					end if;
				--State "LoadRARB"
				when LoadRARB=>
					if(Push='1')then
						if(COP="010")then
							Next_State<=AaddB;
						end if;
						if(COP="011")then
							Next_State<=AsubB;
						end if;
					end if;
				--State "LoadRegI"
				when LoadRegI=>
					if(Push='1')then
						if(COP="100")then
							Next_State<=AincB;
						end if;
						if(COP="101")then
							Next_State<=AdecB;
						end if;
					end if;
				--State "StRAM"
				when StRAM=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "AaddB"
				when AaddB=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "AsubB"
				when AsubB=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "AincB"
				when AincB=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "AdecB"
				when AdecB=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				--State "BEQ"
				when BEQ=>
					if(Push='1')then
						Next_State<=LoadInst;
					end if;
				when others=>
					Next_State<=Idle;
			end case;
		end if;
	end process;
	
	with Next_State select
		ControlWord<=Outputs_Idle when Idle,
						 Outputs_LoadInst when LoadInst,
						 Outputs_Deco when Deco,
						 Outputs_LoadA when LoadA,
						 Outputs_LoadReg when LoadReg,
						 Outputs_StRAM when StRAM,
						 Outputs_LoadRARB when LoadRARB,
						 Outputs_AaddB when AaddB,
						 Outputs_AsubB when AsubB,
						 Outputs_LoadRegI when LoadRegI,
						 Outputs_AincB when AincB,
						 Outputs_AdecB when AdecB,
						 Outputs_BEQ when BEQ,
						 Outputs_Idle when others;

end Behavioral;

