#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

	PresidentialPardonForm();

public:
	static const int sign = 25;
	static const int exec = 5;

	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	PresidentialPardonForm& operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();

	std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<< (std::ostream &out, const PresidentialPardonForm& f);

#endif