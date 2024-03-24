#include <iostream>
#include "Cure.hpp"
#include "debugstream.hpp"

Cure::Cure() : AMateria("cure")
{
	debugStream << "Constructor: Cure!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
	debugStream << "Copy Construct: Cure!" << std::endl;
	operator=(copy);
}

Cure& Cure::operator=(const Cure& rhs)
{
	debugStream << "Copy Assignment: Cure!" << std::endl;
	AMateria::operator=(rhs);
    return *this;
}

Cure::~Cure() {
	debugStream << "Deconstructor: Cure!" << std::endl;
}

AMateria* Cure::clone() const
{
	return (AMateria*)new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

}