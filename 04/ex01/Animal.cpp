#include "Animal.hpp"
Animal::Animal()
{
	std::cout << "Constructor: Animal!" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Copy Construct: Animal!" << std::endl;
	operator=(copy);
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Copy Assignment: Animal!" << std::endl;
	this->type = rhs.type; 
    return *this;
}

Animal::~Animal() {
	std::cout << "Deconstructor: Animal!" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "You hear a noise: *Animal Noises*" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}