#include "BitcoinExchange.hpp"
#include <ctime>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : prices()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& exchange) : prices(exchange.prices)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (&rhs == this)
		return *this;
	this->prices = rhs.prices;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

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
	// 	std::cout << "[\"" << (*i).first << "/" << (*i).second.datestr  << "\"]" << ": " << (*i).second.value << std::endl;
	// }
}

ulong64 BitcoinExchange::DateTimeToInt(const std::string& date, ulong64& dateval)
{
	struct tm	time = {};
	
	char* res = strptime(date.c_str(), "%Y-%m-%d", &time);
	dateval = (ulong64)mktime(&time);
	return (res != NULL);
}

const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t = ws)
{
    return ltrim(rtrim(s, t), t);
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
		trim(datestr);
		trim(pricestr);
		price = atof(pricestr.c_str());
		BitcoinExchange::mapiter iter = prices.lower_bound(date);
		if (iter == prices.end())
			continue;
		if ((*iter).second.dateval > date && iter != prices.begin())
			iter--;
		BTCDate found = (*iter).second;
		if (price < 0)
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
			std::cout << datestr << " => " << price << " = " << price * found.value << std::endl;
		}
	}
}
