--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:54:43 10/25/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto11/Inc_3bits_tb.vhd
-- Project Name:  Proyecto11
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Inc_3bits
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
 
ENTITY Inc_3bits_tb IS
END Inc_3bits_tb;
 
ARCHITECTURE behavior OF Inc_3bits_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Inc_3bits
    PORT(
         Value : IN  std_logic_vector(2 downto 0);
         Value_Inc : INOUT  std_logic_vector(2 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal Value : std_logic_vector(2 downto 0) := (others => '0');

	--BiDirs
   signal Value_Inc : std_logic_vector(2 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   -- constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Inc_3bits PORT MAP (
          Value => Value,
          Value_Inc => Value_Inc
        );

   -- Clock process definitions
   --<clock>_process :process
   --begin
		--<clock> <= '0';
		--wait for <clock>_period/2;
		--<clock> <= '1';
		--wait for <clock>_period/2;
   --end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
     -- wait for 100 ns;	

      --wait for <clock>_period*10;

      -- insert stimulus here 
		
		Value<="000";
		wait for 40 ns;
		
		Value<="001";
		wait for 40 ns;
		
		Value<="010";
		wait for 40 ns;
		
		Value<="011";
		wait for 40 ns;
		
		Value<="100";
		wait for 40 ns;
		
		Value<="101";
		wait for 40 ns;
		
		Value<="110";
		wait for 40 ns;
		
		Value<="111";
		wait for 40 ns;
		
		
      wait;
   end process;

END;
