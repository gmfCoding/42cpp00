#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
#include <iomanip>

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

bool ScalarConverter::isFloat(const std::string& literal, float& value)
{
	if (literal.empty())
		return false;

	char* ptr;
	value = strtof(literal.c_str(), &ptr);
	return ptr[0] == '\0' || ((ptr[0] == 'f') && ptr[1] == '\0');
}

bool ScalarConverter::isDouble(const std::string& literal, double& value)
{
	if (literal.empty())
		return false;

	char* ptr;
	value = strtod(literal.c_str(), &ptr);
	return ptr[0] == '\0';
}

bool ScalarConverter::isInt(const std::string& literal, int& value)
{
	if (literal.empty())
		return false;

	char* ptr;
	value = strtol(literal.c_str(), &ptr, 10);
	return ptr[0] == '\0';
}

bool ScalarConverter::isChar(const std::string& literal, char& value)
{
	if (literal.empty())
		return false;
	if (literal.length() == 1 && isprint(literal[0]))
	{
		value = literal[0];
		return true;
	}
	if (literal[0] != '\'')
		return false;
	if (!isprint(literal[1]))
		return false;
	value = literal[1];
	return true;
}

template<typename T>
struct ValueResult
{
	bool valid;
	T value;
};

struct ScalarResult
{
	ValueResult<int> intval;
	ValueResult<char> charval;
	ValueResult<float> floatval;
	ValueResult<double> doubleval;
};

void ScalarConverter::convert(const std::string& literal)
{
	ScalarResult result;
	result.intval.valid = true;
	result.charval.valid = true;
	result.floatval.valid = true;
	result.doubleval.valid = true;

	if (ScalarConverter::isDouble(literal, result.doubleval.value))
	{
		std::cout << "Double detected!\n";
		double d = result.doubleval.value;
		if (isnan(d) || isinf(d))
		{
			result.intval.valid = false;
			result.charval.valid = false;
		}
		else
		{
			result.intval.value = static_cast<int>(d);
			result.charval.value = static_cast<char>(d);
		}	
		result.floatval.value = static_cast<float>(d);
	}
	else if (ScalarConverter::isFloat(literal, result.floatval.value))
	{
		std::cout << "Float detected!\n";
		float f = result.floatval.value;
		if (isnan(f) || isinf(f))
		{
			result.intval.valid = false;
			result.charval.valid = false;
		}
		else
		{
			result.intval.value = static_cast<int>(f);
			result.charval.value = static_cast<char>(f);
		}
		result.doubleval.value = static_cast<double>(f);
	}
	else if (ScalarConverter::isInt(literal, result.intval.value))
	{
		std::cout << "Int detected!\n";
		int i = result.intval.value;
		result.charval.value = static_cast<char>(i);
		result.floatval.value = static_cast<float>(i);
		result.doubleval.value = static_cast<double>(i);
	}
	else if (ScalarConverter::isChar(literal, result.charval.value))
	{
		std::cout << "Char detected!\n";
		char c = result.charval.value;
		result.charval.value = static_cast<char>(c);
		result.floatval.value = static_cast<float>(c);
		result.doubleval.value = static_cast<double>(c);
	}
	else
	{
		result.intval.valid = false;
		result.charval.valid = false;
		result.floatval.valid = false;
		result.doubleval.valid = false;
	}

	std::cout << "char: ";
	if (result.charval.valid)
	{
		if (isprint(result.charval.value))
			std::cout << '\'' << result.charval.value << '\'';
		else
			std::cout << "Non displayable"; 
	}
	else
		std::cout << "impossible";
	std::cout << '\n';

	std::cout << "int: ";
	if (result.intval.valid)
		std::cout << result.intval.value; 
	else
		std::cout << "impossible";
	std::cout << '\n';

	std::cout << "float: ";
	if (result.floatval.valid)
		std::cout << std::fixed << std::setprecision(1) << result.floatval.value << 'f'; 
	else
		std::cout << "impossible";
	std::cout << '\n';

	std::cout << "double: ";
	if (result.doubleval.valid)
		std::cout << std::fixed << std::setprecision(1) << result.doubleval.value; 
	else
		std::cout << "impossible";
	std::cout << '\n';
}


