#include "IMateriaSource.hpp" 
#include "ICharacter.hpp" 
#include "Character.hpp" 
#include "AMateria.hpp" 
#include "MateriaSource.hpp" 
#include "Ice.hpp" 
#include "Cure.hpp"

#include <iostream>
std::ostream& bold_on(std::ostream& os)
{
    return os << "\e[97;1m";
}

std::ostream& bold_off(std::ostream& os)
{
    return os << "\e[37;0m";
}

void test_1()
{
	std::cout << std::endl << bold_on << "[1] Main test" << bold_off << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}

int main()
{
	test_1();
	return 0;
}