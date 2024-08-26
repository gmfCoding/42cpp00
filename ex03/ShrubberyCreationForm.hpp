#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

	ShrubberyCreationForm();

public:
	static const int sign = 145;
	static const int exec = 137;

	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

	virtual std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<< (std::ostream &out, const ShrubberyCreationForm& f);

#endif