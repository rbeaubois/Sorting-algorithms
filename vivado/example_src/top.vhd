library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity top is
	Port (
		clk : in std_logic;
		led : out std_logic
	);
end top;

architecture Behavioral of top is
	signal counter : integer range 0 to 100000000;
	signal ledv : std_logic;
begin

	process(clk)
	begin
		if rising_edge(clk) then
			if (counter < 100000000) then
				counter <= counter + 1;
			else
				counter <= 0;
				ledv <= not ledv;
			end if;
		end if;
	end process;
	
	led <= ledv;

end Behavioral;