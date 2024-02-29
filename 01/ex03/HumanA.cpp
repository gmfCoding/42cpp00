#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string& _name, Weapon& _weapon) : weapon(_weapon), name(_name)
{

}

void HumanA::attack()
{
	std::cout << this->name << " attacks with their ";
   	std::cout << this->weapon.getType() << std::endl;
}
