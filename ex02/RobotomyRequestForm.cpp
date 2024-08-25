#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm("RobotomyRequestForm", RobotomyRequestForm::sign, RobotomyRequestForm::exec), _target(copy._target)
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	*this = RobotomyRequestForm(rhs._target);
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	(void)executor;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream &out, const RobotomyRequestForm& b)
{
	const AForm& form = b;
    out << form;
	out << ", target: " << b.getTarget();

    return out;
}