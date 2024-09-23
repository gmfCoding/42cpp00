#include "ScalarConverter.hpp"
#include "DecimalConverter.hpp"
#include <iostream>
#include <string>
#include <sstream>

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

static DecimalConverter g_floatConverter("float", 'f');
static DecimalConverter g_doublConverter("double", '\0');
static IntConverter g_intConverter();

void ScalarConverter::convert(const std::string& literal)
{
	AConverter* converters[] =
	{
		&g_floatConverter,
		&g_doublConverter,
		&g_intConverter
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


