#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type)
{
	std::cout << "Constructor: AMateria!" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	std::cout << "Copy Construct: AMateria!" << std::endl;
	operator=(copy);
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
	std::cout << "Copy Assignment: AMateria!" << std::endl;
	this->type = rhs.type; 
    return *this;
}

AMateria::~AMateria() {
	std::cout << "Deconstructor: AMateria!" << std::endl;
}


const std::string& AMateria::getType() const
{
	return (this->type);
}