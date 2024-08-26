#include "Bureaucrat.hpp"

const char * Bureaucrat::GradeTooLowException::what () const throw()
{
	return "Grade too low!";
};

const char * Bureaucrat::GradeTooHighException::what () const throw()
{
	return "Grade too high!";
}

Bureaucrat::Bureaucrat() : _name("Not allowed"), _grade(-1)
{

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
