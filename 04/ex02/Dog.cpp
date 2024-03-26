#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	std::cout << "Constructor: Dog!" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &copy) : AAnimal(copy), brain(NULL)
{
	std::cout << "Copy Constructor: Dog!" << std::endl;
	operator=(copy);
}

Dog& Dog::operator=(const Dog& rhs)
{
	AAnimal::operator=(rhs);
	std::cout << "Copy Assigment: Dog!" << std::endl;
	if (this->brain)
		delete this->brain;
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