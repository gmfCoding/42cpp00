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
};



#endif
