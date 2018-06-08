--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   13:50:43 01/25/2018
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/TDComp/TOP_tb.vhd
-- Project Name:  TDComp
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: TOP
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
 
ENTITY TOP_tb IS
END TOP_tb;
 
ARCHITECTURE behavior OF TOP_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TOP
    PORT(
         Push : IN  std_logic;
         RESET : IN  std_logic;
         CLK : IN  std_logic;
         Instruction : OUT  std_logic_vector(9 downto 0);
         FZ : OUT  std_logic;
         COP : OUT  std_logic_vector(2 downto 0);
         Anodo : OUT  std_logic_vector(3 downto 0);
         Catodo : OUT  std_logic_vector(6 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Push : std_logic := '0';
   signal RESET : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal Instruction : std_logic_vector(9 downto 0);
   signal FZ : std_logic;
   signal COP : std_logic_vector(2 downto 0);
   signal Anodo : std_logic_vector(3 downto 0);
   signal Catodo : std_logic_vector(6 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TOP PORT MAP (
          Push => Push,
          RESET => RESET,
          CLK => CLK,
          Instruction => Instruction,
          FZ => FZ,
          COP => COP,
          Anodo => Anodo,
          Catodo => Catodo
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
      --wait for 100 ns;	

      --wait for CLK_period*10;

      -- insert stimulus here 
		
		RESET<='1';wait for 100 ns;
		RESET<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		

      wait;
   end process;

END;
