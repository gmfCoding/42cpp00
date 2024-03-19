#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor: Cat!" << std::endl;
	type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy) : AAnimal(copy)
{
	std::cout << "Copy Construct: Animal!" << std::endl;
	operator=(copy);
}

Cat& Cat::operator=(const Cat& rhs)
{
	AAnimal::operator=(rhs);
 	std::cout << "Copy Assignment: Cat!" << std::endl;
	this->brain = new Brain(*rhs.brain);
    return *this;
}

Cat::~Cat() {
	std::cout << "Deconstructor: Cat!" << std::endl;
	delete this->brain;
}

bool Cat::isDeepCopy(const Cat* other) const
{
	return (this->brain != other->brain);
}

void Cat::makeSound() const
{
	std::cout << "You hear a noise: *Meow*" << std::endl;
}