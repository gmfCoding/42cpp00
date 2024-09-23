#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();

		ScalarConverter(ScalarConverter& copy);
		ScalarConverter& operator=(ScalarConverter& rhs);

		~ScalarConverter();

	public:
		static void convert(const std::string& input);
		static bool isInt(const std::string& literal, int& value);
		static bool isChar(const std::string& literal, char& value);
		static bool isFloat(const std::string& literal, float& value);
		static bool isDouble(const std::string& literal, double& value);
};



#endif
