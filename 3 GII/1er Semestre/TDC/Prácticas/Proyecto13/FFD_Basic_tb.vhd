--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:37:25 11/08/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto13/FFD_Basic_tb.vhd
-- Project Name:  Proyecto13
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: FFD_Basic
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
 
ENTITY FFD_Basic_tb IS
END FFD_Basic_tb;
 
ARCHITECTURE behavior OF FFD_Basic_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT FFD_Basic
    PORT(
         D : IN  std_logic;
         CLK : IN  std_logic;
         Q : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal D : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal Q : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FFD_Basic PORT MAP (
          D => D,
          CLK => CLK,
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
		

      -- wait for CLK_period*10;

      -- insert stimulus here 
		
		D<='1';
		wait for 100ns;
		D<='0';

   end process;

END;
