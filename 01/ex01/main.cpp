#include "Zombie.hpp"

int main(void)
{
	int	size = 30;
	Zombie* undead = zombieHorde(size, "Benard");
	for (int i = 0; i < size; i++)
		undead[i].announce();
	delete[] undead;
	return (0);
}
