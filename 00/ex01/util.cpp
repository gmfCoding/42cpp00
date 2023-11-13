#include <string>
#include <iostream>

void print_rowcol(std::string before, std::string str, std::string after = "", uint width = 10)
{
	if (str.length() > width)
	{
		str.resize(width);
		str[9] = '.';
	}
	std::cout << before << std::string(width - str.length(), ' ') << str << after;	
}

std::string Prompt(std::string prompt = "")
{
	std::string str;
	while (str.empty())
	{
		std::cout << prompt;
		getline(std::cin, str);
		if (!str.empty())
			return (str);
		std::cout << "Field cannot be empty!" << std::endl;
	}
	return (str);
}