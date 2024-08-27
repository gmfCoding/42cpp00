/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:47:00 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:47:01 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
