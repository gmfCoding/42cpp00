#include <iostream>
#include <string>
#include "megaphone.hpp"

Megaphone::Megaphone(bool _active) : active(_active)
{

}

void Megaphone::Announce(const string& _str)
{
	string str = string(_str);
	if (this->active)
	{
		for (int i = 0; i < str.length(); i++)
			str[i] = toupper(str[i]);
	}
	std::cout << str;
}