#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm : public ShrubberyCreationForm
{
	ShrubberyCreationForm();

public:

	ShrubberyCreationForm(const std::string& name, int grade, int execution);
	ShrubberyCreationForm(const ShrubberyCreationForm& copy);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();

    void beSigned(Bureaucrat& bureaucrat);
	bool canSign(Bureaucrat& Bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;
};

#endif