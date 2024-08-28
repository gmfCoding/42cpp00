#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class ScalarConverter
{
	private:
		ScalarConverter();

		ScalarConverter(ScalarConverter& copy);
		ScalarConverter& operator=(ScalarConverter& rhs);

		~ScalarConverter();

	public:
		static void convert(std::string input);
};



#endif
