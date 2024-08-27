/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:45:57 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:45:58 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
	private:
	const std::string _name;
	int _grade;

	Bureaucrat();

public:
	struct GradeTooHighException : public std::exception
	{
		const char * what () const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char * what () const throw();
	};

	std::string getName() const;
	int getGrade() const;
	bool canSign(const AForm &form) const;
	bool canExecute(const AForm &form) const;

	void incrementGrade();
	void decrementGrade();
	void validateGrade();

	bool signForm(AForm& form);

	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat &rhs);
	~Bureaucrat();
};

std::ostream& operator <<(std::ostream &out, const Bureaucrat& b);

#endif
