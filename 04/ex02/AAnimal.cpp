#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Constructor: Animal!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	std::cout << "Copy Construct: Animal!" << std::endl;
	operator=(copy);
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "Copy Assignment: Animal!" << std::endl;
	this->type = rhs.type; 
    return *this;
}

AAnimal::~AAnimal() {
	std::cout << "Destructor: Animal!" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "You hear a noise: *Animal Noises*" << std::endl;
}

std::string AAnimal::getType() const
{
	return (this->type);
}