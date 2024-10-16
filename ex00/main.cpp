#include "BitcoinExchange.hpp"
#include <fstream>

int main()
{
	std::ifstream file;
	file.open("data.csv");
	
	BitcoinExchange exchange(file);
	file.close();
	return 0;
}
