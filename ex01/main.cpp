#include "tarray.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

struct Place
{
	std::string name;
	int settled_date;
	int population;
};

std::string random_name()
{
	std::string chars = "BCDFGHKMNPPRSTVWXZ";
	std::string vowels = "AEIOU";

	std::string result;
	result += chars[rand() % chars.length()];
	if (rand() % 2 == 0)
		result += chars[rand() % chars.length()];
	for (int i = 0; i < (rand() % 2) + 1; i++)
		result += vowels[rand() % vowels.length()];
	result += chars[rand() % chars.length()];
	return result;
}


void iter_place_print(Place* place)
{
	std::cout << "Name:\t\t" << place->name << "\n";
	std::cout << "Settled Date:\t" << place->settled_date << "\n";
	std::cout << "Population:\t" << place->population << "\n";
	std::cout << std::endl;
}

int main()
{
	Place places[10];
	for (size_t i = 0; i < sizeof(places) / sizeof(Place); i++)
	{
		places[i].name = random_name();
		places[i].population = rand() % 9999 + 2000;
		places[i].settled_date = rand() % 1500 + 200;
	}
	iter(places, sizeof(places) / sizeof(Place), iter_place_print);
	return 0;
}
