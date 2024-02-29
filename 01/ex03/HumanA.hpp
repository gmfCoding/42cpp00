#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon& weapon;
	std::string name;
	
	public:
	HumanA(const std::string& _name, Weapon& _weapon);
	void attack();
};

#endif


