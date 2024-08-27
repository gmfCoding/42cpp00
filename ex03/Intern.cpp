/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:46:04 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:46:06 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& copy)
{
	static_cast<void>(copy);
}

Intern& Intern::operator=(Intern& rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

Intern::~Intern()
{

}

static AForm* makePardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

static AForm* makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

typedef AForm* (*FormGenerator)(std::string target);

struct FormBuilder
{
	std::string aliases[5];
	FormGenerator generator;
};

FormBuilder builders[] = {
	{
		{"pardon", "pardon form", "presidential pardon", "presidential pardon form", "PresidentialPardonForm"},
		&makePardon
	},
	{
		{"robotomy", "robotomy form", "robotomy request", "robotomy request form", "RobtomyRequestForm"},
		&makeRobotomy
	},
	{
		{"shrubbery", "shrubbery form", "shrubbery creation", "shrubbery creation form", "ShrubberyCreationForm"},
		&makeShrubbery
	}
};

AForm* Intern::makeForm(std::string name, std::string target)
{
	for	(size_t i = 0; i < sizeof(builders) / sizeof(FormBuilder); i++)
	{
		for (size_t j = 0; j < sizeof(builders[i].aliases) / sizeof(std::string); j++)
		{
			if (name != builders[i].aliases[j])
				continue;
			std::cout << "Intern creates " << name << std::endl;
			return builders[i].generator(target);
		}
	}
	std::cout << "Intern cannot find form for: " << name << std::endl;
	return NULL;
}
