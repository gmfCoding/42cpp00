#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Constructor: Dog!" << std::endl;
	type = "Dog";
	this->brain = new Brain();
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
	this->brain = new Brain(*rhs.brain);
    return *this;
}

bool Dog::isDeepCopy(const Dog* other) const
{
	return (this->brain != other->brain);
}

Dog::~Dog() {
	std::cout << "Destructor: Dog!" << std::endl;
	delete this->brain;
}

void Dog::makeSound() const
{
	std::cout << "You hear a noise: *Wooof*" << std::endl;
}