#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Constructor: Cat!" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << "Copy Construct: Animal!" << std::endl;
	operator=(copy);
}

Cat& Cat::operator=(const Cat& rhs)
{
	Animal::operator=(rhs);
 	std::cout << "Copy Assignment: Cat!" << std::endl;
    return *this;
}

Cat::~Cat() {
	std::cout << "Deconstructor: Cat!" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "You hear a noise: *Meow*" << std::endl;
}