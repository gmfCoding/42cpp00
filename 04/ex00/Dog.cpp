#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor: Dog!" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << "Copy Constructor: Dog!" << std::endl;
	operator=(copy);
}

Dog& Dog::operator=(const Dog& rhs)
{
	Animal::operator=(rhs);
	std::cout << "Copy Assigment: Dog!" << std::endl;
    return *this;
}

Dog::~Dog() {
	std::cout << "Destructor: Dog!" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "You hear a noise: *Wooof*" << std::endl;
}