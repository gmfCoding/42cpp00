/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:46:51 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:46:51 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PresidentialPardonForm::sign, PresidentialPardonForm::exec), _target("default")
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", PresidentialPardonForm::sign, PresidentialPardonForm::exec), _target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm("PresidentialPardonForm", PresidentialPardonForm::sign, PresidentialPardonForm::exec), _target(copy._target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_target = rhs._target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
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

	std::cout << "To: " << getTarget() << ", you have been presidentially pardon by Zaphod Beeblebrox\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}

std::ostream& operator<<(std::ostream &out, const PresidentialPardonForm& b)
{
	const AForm& form = b;
	out << form;
	out << ", target: " << b.getTarget();

	return out;
}
