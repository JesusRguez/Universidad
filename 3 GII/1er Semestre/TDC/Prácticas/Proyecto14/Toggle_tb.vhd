--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:34:43 11/08/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto14/Toggle_tb.vhd
-- Project Name:  Proyecto14
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Toggle
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
 
ENTITY Toggle_tb IS
END Toggle_tb;
 
ARCHITECTURE behavior OF Toggle_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Toggle
    PORT(
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         ENABLE : IN  std_logic;
         Q : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';
   signal ENABLE : std_logic := '0';

 	--Outputs
   signal Q : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Toggle PORT MAP (
          CLK => CLK,
          RESET => RESET,
          ENABLE => ENABLE,
          Q => Q
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

      --wait for CLK_period*10;

      -- insert stimulus here 
		ENABLE<='1';
		wait for 40ns;
		ENABLE<='0';
		wait for 40ns;
      
   end process;

END;
