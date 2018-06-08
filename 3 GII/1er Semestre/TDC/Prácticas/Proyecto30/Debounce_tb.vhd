--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:07:00 01/10/2018
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto30/Debounce_tb.vhd
-- Project Name:  Proyecto30
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Debounce
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
 
ENTITY Debounce_tb IS
END Debounce_tb;
 
ARCHITECTURE behavior OF Debounce_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Debounce
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         Push : IN  std_logic;
         FilteredPush : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal Push : std_logic := '0';

 	--Outputs
   signal FilteredPush : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Debounce PORT MAP (
          CLK => CLK,
          RESET => RESET,
          Push => Push,
          FilteredPush => FilteredPush
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
		
		RESET<='1';
		wait for 20ns;
		RESET<='0';
		wait for 100ns;
		
		Push<='1';
		wait for 20ns;
		Push<='0';
		wait for 20ns;
		Push<='1';
		wait for 20ns;
		Push<='0';
		wait for 20ns;
		Push<='1';
		wait for 20ns;
		Push<='0';
		
		wait for 300ms;
		Push<='1';
		wait for 300ms;
		Push<='0';
		

      wait;
   end process;

END;
