#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& _name) : name(_name) 
{

}

void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	std::cout << this->name << " attacks with their ";
	if (this->weapon != NULL)
   		std::cout << this->weapon->getType() << std::endl;
	else
		std::cout << " hands" << std::endl; // Is this neccessary?
}

