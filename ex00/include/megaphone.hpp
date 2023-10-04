#ifndef MEGAPHONE_HPP
# define MEGAPHONE_HPP
#include <string>

using std::string;

class Megaphone
{
	bool active;
	public:
	Megaphone(bool _active);
	void Announce(const string& _str);
};
#endif
