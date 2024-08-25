#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _grade;
	bool _signed;
	const int _execute;

	Form();

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
	bool getSigned() const;
	int getExecute() const;

	void validateGrade();

	Form(const std::string& name, int grade, int execution);
	Form(const Form& copy);
	Form& operator=(const Form &rhs);
	~Form();

	void beSigned(Bureaucrat& bureaucrat);
	bool canSign(Bureaucrat& Bureaucrat);
};

std::ostream& operator<< (std::ostream &out, const Form& f);

#endif