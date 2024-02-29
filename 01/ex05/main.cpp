#include "Harl.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Harl harl;

	while(1)
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
	}
}
