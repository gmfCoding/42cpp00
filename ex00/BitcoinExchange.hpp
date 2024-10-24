#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include "BTCDate.hpp"
#include <iostream>
#include <map>

class BitcoinExchange
{

private:
	std::map<ulong64, BTCDate> prices;
	typedef std::map<ulong64, BTCDate>::iterator mapiter;
	BitcoinExchange();

public:
	BitcoinExchange(std::istream& file);
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
	virtual ~BitcoinExchange();

	void Process(std::istream& file);

	ulong64 DateTimeToInt(const std::string& date,  ulong64& dateval);
};
#endif
