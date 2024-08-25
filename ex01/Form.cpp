#include "Bureaucrat.hpp"
#include "Form.hpp"

const char * Form::GradeTooLowException::what () const throw()
{
	return "Grade too low!";
};

const char * Form::GradeTooHighException::what () const throw()
{
	return "Grade too high!";
}

Form::Form() : _name("Not allowed"), _grade(-1), _signed(false), _execute(-1)
{

}

Form::Form(const std::string& name, int grade, int execute) : _name(name), _grade(grade), _signed(false), _execute(execute)
{
    validateGrade();
}

Form::Form(const Form& copy) : _name(copy._name), _grade(copy._grade), _signed(copy._signed), _execute(copy._execute)   
{
    validateGrade();
}

Form& Form::operator=(const Form &rhs)
{
    *this = Form(rhs._name, rhs._grade, rhs._execute);
    this->_signed = rhs._signed;
    return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
   return _name;
}

int Form::getGrade() const
{
    return _grade;
}

int Form::getExecute() const
{
    return _execute;
}

bool Form::getSigned() const
{
    return _signed;
}

std::ostream& operator<< (std::ostream &out, const Form& b)
{
    out << "form: " << b.getName();
    out << ", signature grade: " << b.getGrade();
    out << ", execution grade: " << b.getExecute();
    return out;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.signForm(*this) == false)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

void Form::validateGrade()
{
    if (_grade < 1)
        throw Form::GradeTooHighException();
    if (_grade > 151)
        throw Form::GradeTooLowException();
}
