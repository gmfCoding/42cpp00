#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "Constructor: WrongAnimal!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "Copy Construct: WrongAnimal!" << std::endl;
	operator=(copy);
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "Copy Assignment: WrongAnimal!" << std::endl;
	this->type = rhs.type; 
    return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Deconstructor: WrongAnimal!" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "You hear a noise: *Noises* (WrongAnimal)" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}