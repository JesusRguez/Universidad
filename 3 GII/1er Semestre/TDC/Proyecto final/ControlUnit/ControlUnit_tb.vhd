--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:10:28 01/25/2018
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/PFP5/ControlUnit_tb.vhd
-- Project Name:  PFP5
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ControlUnit
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
 
ENTITY ControlUnit_tb IS
END ControlUnit_tb;
 
ARCHITECTURE behavior OF ControlUnit_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ControlUnit
    PORT(
         Push : IN  std_logic;
         RESET : IN  std_logic;
         CLK : IN  std_logic;
         FZ : IN  std_logic;
         COP : IN  std_logic_vector(2 downto 0);
         ControlWord : OUT  std_logic_vector(14 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Push : std_logic := '0';
   signal RESET : std_logic := '0';
   signal CLK : std_logic := '0';
   signal FZ : std_logic := '0';
   signal COP : std_logic_vector(2 downto 0) := (others => '0');

 	--Outputs
   signal ControlWord : std_logic_vector(14 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ControlUnit PORT MAP (
          Push => Push,
          RESET => RESET,
          CLK => CLK,
          FZ => FZ,
          COP => COP,
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
		
		RESET<='1';wait for 100 ns;
		RESET<='0';wait for 40 ns;
		
		--Idle
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="000";--Va a LoadA
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadA
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="001";--Va a LoadReg
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadReg
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--StRAM
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="010";--Va a LoadRARB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadRARB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--AaddB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="011";--Va a LoadRARB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadRARB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--AsubB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="100";--Va a LoadRegI
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadRegI
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--AincB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="101";--Va a LoadRegI
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadRegI
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--AdecB
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--Deco
		COP<="110";--Va a LoadInst
		FZ<='0';
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--LoadInst
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;		
		
		--Deco
		COP<="110";--Va a LoadInst
		FZ<='1';
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		
		--BEQ
		Push<='1';wait for 20 ns;
		Push<='0';wait for 40 ns;
		

      wait;
   end process;

END;
