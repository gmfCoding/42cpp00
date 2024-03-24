#include <iostream>
#include "AMateria.hpp"
#include "debugstream.hpp"

AMateria::AMateria(std::string const & type) : type(type)
{
	debugStream << "Constructor: AMateria!" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	debugStream << "Copy Construct: AMateria!" << std::endl;
	operator=(copy);
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	debugStream << "Copy Assignment: AMateria!" << std::endl;
	this->type = rhs.type; 
    return *this;
}

AMateria::~AMateria() {
	debugStream << "Deconstructor: AMateria!" << std::endl;
}

const std::string& AMateria::getType() const
{
	return (this->type);
}