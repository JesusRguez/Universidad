--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:18:19 11/08/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto15/RisingEdge_tb.vhd
-- Project Name:  Proyecto15
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: RisingEdge
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
 
ENTITY RisingEdge_tb IS
END RisingEdge_tb;
 
ARCHITECTURE behavior OF RisingEdge_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT RisingEdge
    PORT(
         RESET : IN  std_logic;
         PUSH : IN  std_logic;
         CLK : IN  std_logic;
         Pulse : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal RESET : std_logic := '0';
   signal PUSH : std_logic := '0';
   signal CLK : std_logic := '0';

 	--Outputs
   signal Pulse : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 20 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: RisingEdge PORT MAP (
          RESET => RESET,
          PUSH => PUSH,
          CLK => CLK,
          Pulse => Pulse
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

		PUSH<='0';
		wait for 40ns;
		PUSH<='1';
		wait for 40ns;
		
      wait;
   end process;

END;
