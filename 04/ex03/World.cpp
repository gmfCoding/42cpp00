#include "World.hpp"

World World::world = World(100);

World& World::get()
{
	return World::world;
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