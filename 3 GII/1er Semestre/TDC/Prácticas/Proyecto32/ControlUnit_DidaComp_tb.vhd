--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   09:37:48 01/12/2018
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto32/ControlUnit_DidaComp_tb.vhd
-- Project Name:  Proyecto32
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ControlUnit_DidaComp
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ControlUnit_DidaComp_tb IS
END ControlUnit_DidaComp_tb;
 
ARCHITECTURE behavior OF ControlUnit_DidaComp_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ControlUnit_DidaComp
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         Push : IN  std_logic;
         COP : IN  std_logic_vector(1 downto 0);
         FlagZero : IN  std_logic;
         ControlWord : OUT  std_logic_vector(9 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal Push : std_logic := '0';
   signal COP : std_logic_vector(1 downto 0) := (others => '0');
   signal FlagZero : std_logic := '0';

 	--Outputs
   signal ControlWord : std_logic_vector(9 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ControlUnit_DidaComp PORT MAP (
          CLK => CLK,
          RESET => RESET,
          Push => Push,
          COP => COP,
          FlagZero => FlagZero,
          ControlWord => ControlWord
        );

   -- Clock process definitions
   CLK_process :process
   begin
		CLK <= '0';
		wait for CLK_period/2;
		CLK <= '1';
		wait for CLK_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for CLK_period*10;

      -- insert stimulus here 
		
		RESET<='1'; wait for 20 ns;
		RESET<='0'; wait for 20 ns;
		--esto es load inst
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		--hasta aqui es deco
		--ahora el mov
		COP<="00"; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		--este es el beq
		COP<="01"; 
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		--este es el add
		COP<="10"; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		--este es el sub
		COP<="11"; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;
		PUSH<='1'; wait for 20 ns;
		PUSH<='0'; wait for 20 ns;

      wait;
   end process;

END;
