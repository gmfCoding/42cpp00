#include "RPNParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
		RPNParser parser(argv[1]);
	else
		std::cout << "Please provide an RPN input string." << std::endl;
}
