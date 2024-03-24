/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:06 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 02:06:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"
#include "debugstream.hpp"
#include "World.hpp"

Character::Character(const std::string& name) : name(name)
{
	for (size_t i = 0; i < len; i++)
		slots[i] = NULL;
	debugStream << "Constructor: Character!" << std::endl;
}

Character::Character(const Character &copy)
{
	debugStream << "Copy Construct: Character!" << std::endl;
	this->name = copy.getName();
	for (size_t i = 0; i < len; i++)
	{
		slots[i] = NULL;
		if (copy.slots[i] != NULL)
			slots[i] = copy.slots[i]->clone();
	}
}

Character& Character::operator=(const Character& rhs)
{
	debugStream << "Copy Assignment: Character!" << std::endl;
	this->name = rhs.getName();
	for (size_t i = 0; i < len; i++)
	{
		slots[i] = NULL;
		if (slots[i] != NULL)
			delete slots[i];
	}
    return *this;
}

Character::~Character() {
	debugStream << "Deconstructor: Character!" << std::endl;
	for (size_t i = 0; i < len; i++)
	{
		if (slots[i] != NULL)
			delete slots[i];
	}
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* mat)
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

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= len)
		return;
	World::get().drop(slots[idx]);
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= len)
		return ;
	AMateria *materia = slots[idx];
	if (materia)
		materia->use(target);
}