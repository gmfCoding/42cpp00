#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<time_t, float> prices;
	BitcoinExchange();

public:
	BitcoinExchange(std::istream& file);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	virtual ~BitcoinExchange();
};
#endif


BitcoinExchange::BitcoinExchange() : prices()
{ }

BitcoinExchange::~BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(std::istream& file) : prices()
{
	std::string date;
	char comma;
	std::string price;
	
	while (true)
	{
		file >> date >> comma >> price;
		if (file.fail() || file.eof())
			break;
		std::cout << date << ", " << price << std::endl;
	}
}

