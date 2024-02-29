#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon* weapon;
	std::string name;
	
	public:
	HumanB(const std::string& _name);

	void setWeapon(Weapon& weapon);
	void attack();
};

#endif
