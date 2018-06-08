--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:04:32 01/17/2018
-- Design Name:   
-- Module Name:   C:/Users/Jesus/Xilinx/Proyecto33/tbDidaComp.vhd
-- Project Name:  Proyecto33
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: DidaComp
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
 
ENTITY tbDidaComp IS
END tbDidaComp;
 
ARCHITECTURE behavior OF tbDidaComp IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT DidaComp
    PORT(
         Push : IN  std_logic;
         CLK : IN  std_logic;
         RESET : IN  std_logic;
         AddressRAM : OUT  std_logic_vector(3 downto 0);
         AddressROM : OUT  std_logic_vector(3 downto 0);
         SalRegA : OUT  std_logic_vector(3 downto 0);
         SalRegB : OUT  std_logic_vector(3 downto 0);
         COP : OUT  std_logic_vector(1 downto 0);
         Instruction : OUT  std_logic_vector(7 downto 0);
         FZ : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal Push : std_logic := '0';
   signal CLK : std_logic := '0';
   signal RESET : std_logic := '0';

 	--Outputs
   signal AddressRAM : std_logic_vector(3 downto 0);
   signal AddressROM : std_logic_vector(3 downto 0);
   signal SalRegA : std_logic_vector(3 downto 0);
   signal SalRegB : std_logic_vector(3 downto 0);
   signal COP : std_logic_vector(1 downto 0);
   signal Instruction : std_logic_vector(7 downto 0);
   signal FZ : std_logic;

   -- Clock period definitions
   constant CLK_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: DidaComp PORT MAP (
          Push => Push,
          CLK => CLK,
          RESET => RESET,
          AddressRAM => AddressRAM,
          AddressROM => AddressROM,
          SalRegA => SalRegA,
          SalRegB => SalRegB,
          COP => COP,
          Instruction => Instruction,
          FZ => FZ
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
      

      -- insert stimulus here 
		
		RESET <= '1';
		wait for 20 ns;
		RESET <= '0';
		wait for 20 ns;
		
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;
		Push<='1'; wait for 40 ns;
		Push<='0'; wait for 60 ns;

      wait;
   end process;

END;
