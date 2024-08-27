/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:47:06 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:47:07 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

	RobotomyRequestForm();

public:
	static const int sign = 72;
	static const int exec = 45;

	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	RobotomyRequestForm& operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();

	std::string getTarget() const;

	virtual void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<< (std::ostream &out, const RobotomyRequestForm& f);

#endif
