#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : name(name)
{
	std::cout << "Constructor: Character!" << std::endl;
}

Character::Character(const Character &copy)
{
	std::cout << "Copy Construct: Character!" << std::endl;
	operator=(copy);
}

Character& Character::operator=(const Character& rhs)
{
	std::cout << "Copy Assignment: Character!" << std::endl;
	this->name = rhs.getName();
    return *this;
}

Character::~Character() {
	std::cout << "Deconstructor: Character!" << std::endl;
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < len_slots; i++)
	{
		if (slots[i] != nullptr)
			continue;
		slots[i] = m;
		break;
	}
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{
	
}