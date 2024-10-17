#include "BitcoinExchange.hpp"
#include <ctime>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : prices()
{ }

BitcoinExchange::~BitcoinExchange()
{ }

BitcoinExchange::BitcoinExchange(std::istream& file) : prices()
{
	std::string header;
	std::getline(file, header);

	while(file.good())
	{
		std::string datestr = "1/1/1970";
		std::string pricestr = "0";
		std::string remaining = "0";

		ulong64 date = 0;
		float price = 0;

		getline(file, datestr, ',');
		getline(file, pricestr, '\n');
		if(datestr.empty() || pricestr.empty())
			continue;
		if (DateTimeToInt(datestr, date) == false)
			continue;
		price = atof(pricestr.c_str());
		prices[date] = BTCDate(date, datestr, price);
	}
	// for(mapiter i = prices.begin(); i != prices.end(); i++)
	// {
	// 	std::cout << "[\"" << (*i).first << "\"]" << ": " << (*i).second << std::endl;
	// }
}

ulong64 BitcoinExchange::DateTimeToInt(const std::string& date, ulong64& dateval)
{
	struct tm	time;

	char* res = strptime(date.c_str(), "%Y-%m-%d", &time);
	dateval = (ulong64)mktime(&time);
	return (res != NULL);
}


void BitcoinExchange::Process(std::istream& file)
{
	std::string header;
	std::getline(file, header);

	while(file.good())
	{
		std::string datestr = "1/1/1970";
		std::string pricestr;
		std::string remaining;
		ulong64 date = 0;
		float price = 0;

		std::string line;
		size_t spos;
		
		getline(file, line, '\n');
		spos = line.find('|');
		datestr = line.substr(0, spos);
		if (spos != line.npos)
			pricestr = line.substr(spos + 1);
		if (datestr.empty() || pricestr.empty() || DateTimeToInt(datestr, date) == false)
		{
			std::cout << "Error: bad input " << datestr << std::endl;
			continue;
		}
		price = atof(pricestr.c_str());
		mapiter found = prices.lower_bound(date);
		if (price < 0 || (*found).second.value < 0)
		{
			std:: cout << "Error: not a positive number" << std::endl;
			continue;
		}
		else if (price > 1000)
		{
			std:: cout << "Error: too large a number" << std::endl;
			continue;
		}
		else
		{
			std::cout << (*found).second.datestr << " => " << price << " = " << price * (*found).second.value << std::endl;
		}
	}
}