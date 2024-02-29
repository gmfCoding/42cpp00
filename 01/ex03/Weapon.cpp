#include "Weapon.hpp"


Weapon::Weapon(const std::string& _type) : type(_type)
{

}

const std::string& Weapon::getType()
{
	return (this->type);
}

void Weapon::setType(const std::string& type)
{
	this->type = type;
}
