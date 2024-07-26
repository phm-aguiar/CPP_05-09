/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:12:13 by phenriq2          #+#    #+#             */
/*   Updated: 2024/07/25 14:51:09 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150){}

Bureaucrat::Bureaucrat(std::string name, int grade)
    : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		const_cast<std::string &>(_name) = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ",bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return (RED "Grade is too high" RESET);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return (RED "Grade is too low" RESET);
}

void Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << RED << _name << " cannot sign " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}	

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
    }
    catch (AForm::GradeTooLowException &e)
    {
        std::cout << RED << _name << " cannot execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
    catch (AForm::FormNotSignedException &e)
    {
        std::cout << RED << _name << " cannot execute " << form.getName() << " because " << e.what() << RESET << std::endl;
    }
}
