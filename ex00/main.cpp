#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (false && argc != 2)
	{
		std::cout << "Too many / not enough arguments, there most only be one!\n";
		return 1;
	}
	ScalarConverter::convert("''");
	ScalarConverter::convert(argv[1]);
	return 0;
}
