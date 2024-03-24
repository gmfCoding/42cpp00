#include <iostream>
#include "Ice.hpp"
#include "debugstream.hpp"

Ice::Ice() : AMateria("ice")
{
	debugStream << "Constructor: Ice!" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
	debugStream << "Copy Construct: Ice!" << std::endl;
	operator=(copy);
}

Ice& Ice::operator=(const Ice& rhs)
{
	AMateria::operator=(rhs);
	debugStream << "Copy Assignment: Ice!" << std::endl;
    return *this;
}

Ice::~Ice() {
	debugStream << "Deconstructor: Ice!" << std::endl;
}


AMateria* Ice::clone() const
{
	return (AMateria*)new Ice(*this);
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}