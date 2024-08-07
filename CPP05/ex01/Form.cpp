#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _signGrade(150), _execGrade(150){}
Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	*this = other;
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(this->_name) = rhs.getName();
		_signed = rhs.getSigned();
		const_cast<int &>(this->_signGrade) = rhs.getSignGrade();
		const_cast<int &>(this->_execGrade) = rhs.getExecGrade();
	}
	return (*this);
}

Form::~Form(){}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw Form::GradeTooLowException();
	if (_signed)
	{
		std::cout <<RED "Form is already signed" RESET<< std::endl;
		return ;
	}
	_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high for this form");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low for this form");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << " is " << (form.getSigned() ? "signed" : "not signed") << " and requires grade " << form.getSignGrade() << " to sign and grade " << form.getExecGrade() << " to execute";
	return (os);
}