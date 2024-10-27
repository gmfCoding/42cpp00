#include "RPNParser.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		std::string input = std::string(argv[1]);
		if (!input.empty())
		{
			try {
				RPNParser parser(input);
				return 0;
			}
			catch (std::exception& e)
			{
				std::cout << e.what() << std::endl;
				return 1;
			}
		}
	}
	std::cout << "Please provide an RPN input string." << std::endl;
	return 1;
}
