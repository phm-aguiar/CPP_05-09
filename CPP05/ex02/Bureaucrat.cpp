/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:12:13 by phenriq2          #+#    #+#             */
/*   Updated: 2024/07/23 11:17:50 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat()
	: _name("default"), _grade(150)
{
	std::cout << YELLOW <<"Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	_grade = -42;
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	try
	{
		if (grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	_grade = grade;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << YELLOW <<"Copy constructor called" << RESET <<std::endl;
	return ;
}

// Copy assignment overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

// Default destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Destructor called" << RESET <<std::endl;
	return ;
}

// Getters

std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// overload << operator

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ",bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}

// GradeTooHighException class

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too high");
}

// GradeTooLowException class

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low");
}

// incrementGrade method

void Bureaucrat::incrementGrade(void)
{
	_grade--;
	try
	{
		if (_grade < 1)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
		_grade = 1;
	}
	
}

// decrementGrade method

void Bureaucrat::decrementGrade(void)
{
	_grade++;
	try
	{
		if (_grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
		_grade = 150;
	}
}

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << _name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
