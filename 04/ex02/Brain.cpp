#include <iostream>
#include "Brain.hpp"

//const int Brain::ideas_count;

Brain::Brain()
{
	std::cout << "Constructor: Brain!" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Construct: Brain!" << std::endl;
	operator=(copy);
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Copy Assignment: Brain!" << std::endl;
	for (size_t i = 0; i < Brain::ideas_count; i++) // Kind of useless at the moment
		this->ideas[i] = rhs.ideas[i];
    return *this;
}

Brain::~Brain() {
	std::cout << "Deconstructor: Brain!" << std::endl;
}