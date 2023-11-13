#include <string>
#include <iostream>

void print_rowcol(std::string before, std::string str, std::string after = "", int width = 10)
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
	std::cout << prompt;
	getline(std::cin, str);
	return (str);
}
