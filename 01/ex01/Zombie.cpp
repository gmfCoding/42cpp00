#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::SetName(const std::string& str)
{
	name = str;
}

Zombie::Zombie(const std::string& str) : name(str)
{

}

Zombie::~Zombie()
{
	std::cout << "Zombie Killed:" << this->name << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

