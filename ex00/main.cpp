#include "BitcoinExchange.hpp"
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream file;
	file.open("data.csv");

	BitcoinExchange exchange(file);
	file.close();
	if (argc > 1)
	{
		file.open(argv[1]);
		if (file.good())
		{
			exchange.Process(file);
			file.close();
			return 0;
		}
	}
	std::cout << "Error: could not open file" << std::endl;
}
