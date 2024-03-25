/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <clovell@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 02:06:50 by clovell           #+#    #+#             */
/*   Updated: 2024/03/25 20:27:53 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "World.hpp"

World World::world = World(100);

World& World::get()
{
	return World::world;
}

World::World() : capacity(8), count(0), dropped(new AMateria*[8])
{
	for (size_t i = 0; i < capacity; i++)
		dropped[i] = NULL;
}

World::World(unsigned int capacity) : capacity(capacity), count(0)
{
	if (capacity <= 0)
		capacity = 1;
	dropped = new AMateria*[capacity];
	for (size_t i = 0; i < capacity; i++)
		dropped[i] = NULL;
}

World::~World()
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (dropped[i] != NULL)
			delete dropped[i];
	}
	delete[] dropped;
}

World::World(const World &copy)
{
	operator=(copy);
}

World& World::operator=(const World& rhs)
{
	(void)rhs;
	return *this;
}

void	World::drop(AMateria* &mat)
{
	dropped[count] = mat;
	mat = NULL;
	count++;
	if (count >= capacity)
		resize();
}

void World::resize(void)
{
	AMateria**	array = new AMateria*[capacity * 2];
	for (size_t i = 0; i < capacity * 2; i++)
	{
		array[i] = NULL;
		if (i < count)
			array[i] = this->dropped[i];
	}
	delete[] this->dropped;
	capacity *= 2;
	this->dropped = array;
}