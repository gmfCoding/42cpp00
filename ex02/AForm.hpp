#ifndef AFORM_HPP
#define AFORM_HPP
#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _grade;	
    bool _signed;
    const int _execute;

	AForm();
	AForm& operator=(const AForm &rhs);

public:
	struct GradeTooHighException : public std::exception
	{
		const char * what () const throw();
	};

	struct GradeTooLowException : public std::exception
	{
		const char * what () const throw();
	};

	struct FormNotSignedException : public std::exception
	{
		const char * what () const throw();
	};

	std::string getName() const;
	int getGrade() const;
	bool getSigned() const;
	int getExecute() const;

	void validateGrade();
	
	AForm(const std::string& name, int grade, int execution);
	AForm(const AForm& copy);
	~AForm();

    void beSigned(Bureaucrat& bureaucrat);
	bool canSign(Bureaucrat& Bureaucrat);

	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<< (std::ostream &out, const AForm& f);

#endif