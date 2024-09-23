#ifndef DECIMALCONVERTER_HPP
#define DECIMALCONVERTER_HPP

#include <string>
#include "AConverter.hpp"
class DecimalConverter: public AConverter
{
private:
	std::string m_name;
	char m_suffix;
	
	DecimalConverter();
		
public:
	DecimalConverter(const std::string& name, char suffix);
	DecimalConverter(const DecimalConverter& copy);
	DecimalConverter& operator=(const DecimalConverter& rhs);	
	~DecimalConverter();
	bool match(const std::string& literal);
	const std::string& getTypeName();
	const std::string convert(const std::string& literal);
};
#endif
