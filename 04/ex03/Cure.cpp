#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{
	std::cout << "Constructor: Cure!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
	std::cout << "Copy Construct: Cure!" << std::endl;
	operator=(copy);
}

Cure& Cure::operator=(const Cure& rhs)
{
	AMateria::operator=(rhs);
	std::cout << "Copy Assignment: Cure!" << std::endl;
    return *this;
}

Cure::~Cure() {
	std::cout << "Deconstructor: Cure!" << std::endl;
}


AMateria* Cure::clone() const
{

}

void Cure::use(ICharacter& target)
{

}