#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{
	std::cout << "Constructor: Ice!" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
	std::cout << "Copy Construct: Ice!" << std::endl;
	operator=(copy);
}

Ice& Ice::operator=(const Ice& rhs)
{
	AMateria::operator=(rhs);
	std::cout << "Copy Assignment: Ice!" << std::endl;
    return *this;
}

Ice::~Ice() {
	std::cout << "Deconstructor: Ice!" << std::endl;
}

AMateria* Ice::clone() const
{

}

void Ice::use(ICharacter& target)
{

}