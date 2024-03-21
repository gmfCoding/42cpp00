#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Constructor: MateriaSource!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : WrongAnimal(copy)
{
	operator=(copy);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	this->type = rhs.type; 
    return *this;
}

MateriaSource::~MateriaSource() {
	std::cout << "Deconstructor: MateriaSource!" << std::endl;
}