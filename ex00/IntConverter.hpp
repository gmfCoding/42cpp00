#ifndef INTCONVERTER_HPP
#define INTCONVERTER_HPP

#include <string>
#include "AConverter.hpp"
class IntConverter: public AConverter
{
private:
	std::string m_name;
	char m_suffix;
	
	IntConverter();
		
public:
	IntConverter(const std::string& name, char suffix);
	IntConverter(const IntConverter& copy);
	IntConverter& operator=(const IntConverter& rhs);	
	~IntConverter();
	bool match(const std::string& literal);
	const std::string& getTypeName();
	const std::string convert(const std::string& literal);
};
#endif
