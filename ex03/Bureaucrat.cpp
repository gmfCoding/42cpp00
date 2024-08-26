#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char * Bureaucrat::GradeTooLowException::what () const throw()
{
	return "Grade too low!";
};

const char * Bureaucrat::GradeTooHighException::what () const throw()
{
	return "Grade too high!";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	validateGrade();
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade)
{
	validateGrade();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &rhs)
{
	//*this = Bureaucrat(rhs._name, rhs._grade);
	if (this == &rhs)
		return (*this);
	
	this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

std::string Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incrementGrade()
{
	_grade--;
	validateGrade();
}

void Bureaucrat::decrementGrade()
{
	_grade++;
	validateGrade();
}

bool Bureaucrat::signForm(AForm &form)
{
	if (this->canSign(form))
	{
		std::cout << *this << " signed " << form << std::endl;
		return true;
	}
	else
	{
		std::cout << *this << " couldn’t sign " << form << " because bureaucrat doesn't have high enough grade." << std::endl;
		return false;
	}
}

bool Bureaucrat::canSign(const AForm &form) const
{
	return this->getGrade() <= form.getGrade();
}

bool Bureaucrat::canExecute(const AForm &form) const
{
	return this->getGrade() <= form.getExecute();
}

std::ostream& operator<< (std::ostream &out, const Bureaucrat& b)
{
	out << "name: " << b.getName() << ", grade: " << b.getGrade();
	return out;
}

void Bureaucrat::validateGrade()
{
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 151)
		throw Bureaucrat::GradeTooLowException();
}
