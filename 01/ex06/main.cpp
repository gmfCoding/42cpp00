#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	if (argc >= 2)
		harl.complainfrom(argv[1]);
}
