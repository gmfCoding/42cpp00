/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:36 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 02:06:37 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

void test_2()
{
	std::cout << std::endl << bold_on << "[2] Secondary test" << bold_off << std::endl;
	
	ICharacter* me;

	{
		Character* me2 = new Character("me");
		me = new Character(*me2);
		delete me2;
	}

	IMateriaSource* src;
	{
		MateriaSource* src2 = new MateriaSource();
		src = new MateriaSource(*src2);
		delete src2;
	}
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	// Slot overwriting test
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("cure"));
	me->equip(src->createMateria("ice"));

	ICharacter* bob = new Character("bob");

	// available spells
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);

	// Out of rnage available spells
	me->use(4, *bob);

	// No available spells
	bob->use(0, *me);
	bob->use(1, *me);
	bob->use(2, *me);
	bob->use(3, *me);

	// Out of range no available spells
	bob->use(4, *me);
	
	delete bob;
	delete me;
	delete src;
}


int main()
{
	test_1();
	test_2();
	return 0;
}