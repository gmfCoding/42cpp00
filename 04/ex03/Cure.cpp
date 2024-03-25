/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:11 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 18:47:34 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Cure.hpp"
#include "debugstream.hpp"

Cure::Cure() : AMateria("cure")
{
	debugStream << "Constructor: Cure!" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
	debugStream << "Copy Construct: Cure!" << std::endl;
	operator=(copy);
}

Cure& Cure::operator=(const Cure& rhs)
{
	debugStream << "Copy Assignment: Cure!" << std::endl;
	AMateria::operator=(rhs);
    return *this;
}

Cure::~Cure() {
	debugStream << "Deconstructor: Cure!" << std::endl;
}

AMateria* Cure::clone() const
{
	return (AMateria*)new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

}