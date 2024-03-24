#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	static const int	len = 4;

	int					next;
	AMateria			*slots[len];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource& operator=(const MateriaSource& rhs);
	~MateriaSource();

	void learnMateria(AMateria *materia);
	AMateria* createMateria(std::string const & type);
};
#endif