#include "Zombie.hpp"

int main(void)
{
	Zombie* nz = newZombie("Fred");

	nz->announce();
	randomChump("John");
	delete nz;
	return (0);
}