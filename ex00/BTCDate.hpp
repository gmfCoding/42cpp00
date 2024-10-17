#ifndef BTCDATE_HPP
#define BTCDATE_HPP
#include <string>

typedef unsigned long ulong64;

struct BTCDate
{
	ulong64		dateval;
	std::string	datestr;
	float		value;

	BTCDate();
	BTCDate(const ulong64 dateval, const std::string& datestr, const float value);
};

#endif