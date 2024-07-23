#include "AForm.hpp"

// Default constructor
AForm::AForm()
	: _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	return ;
}
AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}


// Copy constructor
AForm::AForm(const AForm &other) : _name("default"), _signed(false), _signGrade(150), _execGrade(150)
{
	*this = other;
	return ;
}

// Copy assignment overload
AForm &AForm::operator=(const AForm &rhs)
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

// Default destructor
AForm::~AForm()
{
	return ;
}

// getters

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

int AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (_execGrade);
}

// methods

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

// exception classes

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high for this Aform");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low for this Aform");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm " << Aform.getName() << " is " << (Aform.getSigned() ? "signed" : "not signed") << " and requires grade " << Aform.getSignGrade() << " to sign and grade " << Aform.getExecGrade() << " to execute";
	return (os);
}