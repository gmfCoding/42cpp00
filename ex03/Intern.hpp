#ifndef INTERN_HPP
#define INTERN_HPP
#include <string>
#include "AForm.hpp"

class Intern
{

public:
	Intern();
	Intern(const Intern& copy);
	Intern& operator=(Intern& rhs);
	~Intern();

	AForm* makeForm(std::string name, std::string target);
};

#endif
