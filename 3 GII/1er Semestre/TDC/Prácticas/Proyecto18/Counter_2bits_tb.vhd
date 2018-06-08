--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   10:33:42 11/15/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto18/Counter_2bits_tb.vhd
-- Project Name:  Proyecto18
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Counter_2bits
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
 
ENTITY Counter_2bits_tb IS
END Counter_2bits_tb;
 
ARCHITECTURE behavior OF Counter_2bits_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Counter_2bits
    PORT(
         ENABLE : IN  std_logic;
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         Q : OUT  std_logic_vector(1 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal ENABLE : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';

 	--Outputs
   signal Q : std_logic_vector(1 downto 0);

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Counter_2bits PORT MAP (
          ENABLE => ENABLE,
          CLK => CLK,
          RESET => RESET,
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

      wait for CLK_period*10;

      -- insert stimulus here 
		
		RESET<='1';
		wait for 40 ns;
		
		ENABLE<='1';
		
		wait for 100 ns;

      wait;
   end process;

END;
