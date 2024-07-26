#include "AForm.hpp"

AForm::AForm()
	: _name("default"), _signed(false), _signGrade(150), _execGrade(150){}
	
AForm::AForm(std::string name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name), _signed(other._signed), _signGrade(other._signGrade),
		_execGrade(other._execGrade){}

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

AForm::~AForm(){}

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
	if (bureaucrat.getGrade() > _signGrade)
		throw AForm::GradeTooLowException();
	if (_signed)
	{
		std::cout << "Form is already signed" << std::endl;
		return ;
	}
	_signed = true;
	std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
}

// exception classes

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade is too high for this Aform" RESET);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade is too low for this Aform" RESET);
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return (RED "Form is not signed" RESET);
}

std::ostream &operator<<(std::ostream &os, const AForm &aform) {
    os << GREEN << "AForm " << aform.getName() << " is " << (aform.getSigned() ? "signed" : "not signed")
       << " and requires grade " << aform.getSignGrade() << " to sign and grade " << aform.getExecGrade()
       << " to execute" << RESET << std::endl;
    return os;
}