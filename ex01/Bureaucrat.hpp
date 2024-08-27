/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clovell <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:41:41 by clovell           #+#    #+#             */
/*   Updated: 2024/08/27 16:41:42 by clovell          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>
#include <exception>
#include <iostream>

class Form;

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
	bool canSign(const Form &form) const;

	void incrementGrade();
	void decrementGrade();
	void validateGrade();

	bool signForm(Form& form);

	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat &rhs);
	~Bureaucrat();
};

std::ostream& operator <<(std::ostream &out, const Bureaucrat& b);

#endif
