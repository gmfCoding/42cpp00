#include <iostream>
#include "megaphone.hpp"

int main(int argc, char **argv)
{
	Megaphone phone(true);
	int	i = 1;
	
	while (i < argc)
	{
		phone.Announce(argv[i]);
		i++;
	}
	if (argc == 1)
		phone.Announce("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	std::cout << std::endl;
}
