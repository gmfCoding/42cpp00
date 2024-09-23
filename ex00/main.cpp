#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
	std::string str;
	if (argc != 2)
		str = "'a'";
	else
		str = argv[1];
	ScalarConverter::convert(str);
	return 0;
}
