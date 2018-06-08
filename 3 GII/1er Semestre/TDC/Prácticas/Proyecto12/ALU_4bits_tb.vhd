--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   12:47:58 10/25/2017
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto12/ALU_4bits_tb.vhd
-- Project Name:  Proyecto12
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ALU_4bits
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
 
ENTITY ALU_4bits_tb IS
END ALU_4bits_tb;
 
ARCHITECTURE behavior OF ALU_4bits_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ALU_4bits
    PORT(
         OPE_A : IN  std_logic_vector(3 downto 0);
         OPE_B : IN  std_logic_vector(3 downto 0);
         SEL_ALU : IN  std_logic_vector(1 downto 0);
         Sal_ALU : OUT  std_logic_vector(3 downto 0);
         SalFZ : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal OPE_A : std_logic_vector(3 downto 0) := (others => '0');
   signal OPE_B : std_logic_vector(3 downto 0) := (others => '0');
   signal SEL_ALU : std_logic_vector(1 downto 0) := (others => '0');

 	--Outputs
   signal Sal_ALU : std_logic_vector(3 downto 0);
   signal SalFZ : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
   --constant <clock>_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ALU_4bits PORT MAP (
          OPE_A => OPE_A,
          OPE_B => OPE_B,
          SEL_ALU => SEL_ALU,
          Sal_ALU => Sal_ALU,
          SalFZ => SalFZ
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
		
		OPE_A<="0110";
		OPE_B<="0000";
		SEL_ALU<="00";
		wait for 40 ns;
		
		OPE_A<="0100";
		OPE_B<="1100";
		SEL_ALU<="01";
		wait for 40 ns;
		
		OPE_A<="1100";
		OPE_B<="0011";
		SEL_ALU<="10";
		wait for 40 ns;
		
		OPE_A<="1100";
		OPE_B<="0011";
		SEL_ALU<="11";
		wait for 40 ns;
		
		OPE_A<="1100";
		OPE_B<="1111";
		SEL_ALU<="11";
		wait for 40 ns;
		
      wait;
   end process;

END;
