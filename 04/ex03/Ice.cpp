/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:19 by clovell           #+#    #+#             */
/*   Updated: 2024/03/26 14:56:48 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
	debugStream << "Destructor: Ice!" << std::endl;
}


AMateria* Ice::clone() const
{
	return (AMateria*)new Ice(*this);
}


void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}