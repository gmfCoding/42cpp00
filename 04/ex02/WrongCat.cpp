#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "Constructor: WrongCat!" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	operator=(copy);
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	this->type = rhs.type; 
    return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor: WrongCat!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "You hear a noise: *Oooh oooh AH AH!* (WrongCat)" << std::endl;
}