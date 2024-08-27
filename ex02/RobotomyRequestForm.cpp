/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:44:39 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:44:40 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
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
	if (this == &rhs)
		return (*this);
	this->_target = rhs._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
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

	std::cout << ".,Bzz#rtt *Intense Drilling Noises* .,Bzz#rtt\n";

	std::string outcome = "successfull, congratulations.";
	if (std::rand() % 2 == 0)
		outcome = "unsuccesfull, better luck next time.";
	std::cout << "Hello " << getTarget() << " your robotomization has been " << outcome << std::endl;
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
