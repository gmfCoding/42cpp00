#include "ScalarConverter.hpp"
#include <iostream>

class AConverter
{
public:
	virtual bool match(const std::string& literal) = 0;
	virtual const std::string& getTypeName() = 0;
	virtual const std::string& convert(const std::string& literal) = 0;
};

class DecimalConverter: public AConverter
{
private:
	std::string m_name;
	char m_prefix;
	
	DecimalConverter();
		
public:
	DecimalConverter(const std::string& name, char prefix);
	DecimalConverter(const DecimalConverter& copy);
	DecimalConverter& operator=(const DecimalConverter& rhs);	
	~DecimalConverter();
	bool match(const std::string& literal);
	const std::string& getTypeName();
	const std::string& convert(const std::string& literal);
};

bool DecimalConverter::match(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	char* ptr;
	strtof(literal.c_str(), &ptr);
	return ptr[0] == '\0' || (ptr[0] == m_prefix && ptr[1] == '\0');
}

std::string DecimalConverter::match(const std::string& literal)
{
	if (literal.empty())
		return false;
	
	char* ptr;
	double value = strtord(literal.c_str(), &ptr);
	std::string result;

	if (!(ptr[0] == '\0' || (ptr[0] == m_prefix && ptr[1] == '\0')))
		return "impossible";
	if (value < 0.0)
		result += "-";
	if (isinf(value))
		result += "inf";
	if (isnan(value))
		result += "nan";
	else
		result += m_prefix;
}
const std::string& DecimalConverter::getTypeName()
{
	return m_name;
}


ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter& copy)
{
	static_cast<void>(copy);
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

void ScalarConverter::convert(const std::string& literal)
{
	AConverter* converters[] =
	{
		new DecimalConverter("float", 'f'),
		new DecimalConverter("double", '\0'),
	};

	for (size_t i = 0; i < sizeof(converters) / sizeof(*converters); i++)
	{
		AConverter* conv = converters[i];
		if (conv->match(literal))
			std::cout << conv->getTypeName() << ": " << conv->convert(literal);
		else
			std::cout << conv->getTypeName() << ": " << "impossible";
		std::cout << std::endl;
	}
}


