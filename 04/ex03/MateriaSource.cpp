#include <iostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "debugstream.hpp"

MateriaSource::MateriaSource() : next(0)
{
	for (size_t i = 0; i < len; i++)
		slots[i] = NULL;
	debugStream << "Constructor: MateriaSource!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy) : next(0)
{
	debugStream << "Copy constructor: MateriaSource" << std::endl;

	operator=(copy);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	debugStream << "Copy assignment / operator=: MateriaSource" << std::endl;

	if (&rhs == this)
		return *this;
	for (size_t i = 0; i < len; i++)
	{
		this->slots[i] = NULL;
		if (rhs.slots[i] != NULL)
			this->slots[i] = rhs.slots[i]->clone();
	}
    return *this;
}

MateriaSource::~MateriaSource() {
	debugStream << "Deconstructor: MateriaSource!" << std::endl;

	for (size_t i = 0; i < len; i++)
	{
		if (this->slots[i] != NULL)
			delete this->slots[i];
	}
}

void MateriaSource::learnMateria(AMateria *mat)
{
	bool added = false;

	for (size_t i = 0; i < len; i++)
	{
		if (slots[i] != NULL)
			continue;
		added = true;
		slots[i] = mat;
		break;
	}
	if (!added)
		delete mat;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < len; i++)
	{
		if (this->slots[i] == NULL)
			continue;
		if (slots[i]->getType() == type)
			return slots[i]->clone();
	}
	return 0;
}