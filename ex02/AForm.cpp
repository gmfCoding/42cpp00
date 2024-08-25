#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char * AForm::GradeTooLowException::what () const throw()
{
	return "Grade too low!";
};

const char * AForm::GradeTooHighException::what () const throw()
{
	return "Grade too high!";
}

AForm::AForm() : _name("Not allowed"), _grade(-1), _signed(false), _execute(-1)
{

}

AForm::AForm(const std::string& name, int grade, int execute) : _name(name), _grade(grade), _signed(false), _execute(execute)
{
    validateGrade();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _grade(copy._grade), _signed(copy._signed), _execute(copy._execute)   
{
    validateGrade();
}

AForm& AForm::operator=(const AForm &rhs)
{
    *this = AForm(rhs._name, rhs._grade, rhs._execute);
    this->_signed = rhs._signed;
    return (*this);
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
   return _name;
}

int AForm::getGrade() const
{
    return _grade;
}

int AForm::getExecute() const
{
    return _execute;
}

bool AForm::getSigned() const
{
    return _signed;
}

std::ostream& operator<< (std::ostream &out, const AForm& b)
{
    out << "Aform: " << b.getName();
    out << ", signature grade: " << b.getGrade();
    out << ", execution grade: " << b.getExecute();
    return out;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.signAForm(*this) == false)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

void AForm::validateGrade()
{
    if (_grade < 1)
        throw AForm::GradeTooHighException();
    if (_grade > 151)
        throw AForm::GradeTooLowException();
}
