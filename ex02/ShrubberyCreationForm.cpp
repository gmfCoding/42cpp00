#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm("ShrubberyCreationForm", ShrubberyCreationForm::sign, ShrubberyCreationForm::exec), _target(copy._target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	*this = ShrubberyCreationForm(rhs._target);
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::cout << executor << " executing: " << *this;

	if (executor.canExecute(*this) == false)
	{
		std::cout << " -- [FAILED]" << std::endl;
		throw AForm::GradeTooLowException();
	}
	if (getSigned() == false)
	{
		std::cout << " -- [FAILED]" << std::endl;
		throw AForm::FormNotSignedException();
	}

	std::cout << " -- [SUCCESS]" << std::endl;

	std::string data = 
		 "         # #### ####            \n"
         "       ### \\/#|### |/####       \n"
         "      ##\\/#/ \\||/##/_/##/_#     \n"
         "    ###  \\/###|/ \\/ # ###       \n"
         "  ##_\\_#\\_\\## | #/###_/_####    \n"
         " ## #### # \\ #| /  #### ##/##   \n"
         "  __#_--###`  |{,###---###-~    \n"
         "            \\ }{                \n"
         "             }}{                \n"
         "             }}{                \n"
         "        ejm  {{}                \n"
         "       , -=-~{ .-^- _           \n"
         "             `}                 \n"
         "              {               \n";

	std::ofstream outfile(getTarget().c_str());
	outfile << data << std::endl;
	outfile.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

std::ostream& operator<<(std::ostream &out, const ShrubberyCreationForm& b)
{
	const AForm& form = b;
    out << form;
	out << ", target: " << b.getTarget();

    return out;
}