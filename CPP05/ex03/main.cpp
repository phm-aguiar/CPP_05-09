#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testCreateRobotomyRequestForm(void)
{
	Intern	intern;
	AForm	*form;

	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		form = intern.makeForm("robotomy request", "ClapTrap form");
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCreatePresidentialPardonForm(void)
{
	Intern	intern;
	AForm	*form;
	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		form = intern.makeForm("presidential pardon", "share sale form");
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	testCreateShrubberyCreationForm(void)
{
	Intern	intern;
	AForm	*form;

	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		form = intern.makeForm("shrubbery creation", "mortgage form");
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testCreateInvalidForm(void)
{
	Intern	intern;
	AForm	*form;

	try
	{
		Bureaucrat bureaucrat("bureaucrat", 1);
		form = intern.makeForm("invalid form", "invalid form");
		bureaucrat.signForm(*form);
		form->execute(bureaucrat);
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	testCreateRobotomyRequestForm();
	testCreatePresidentialPardonForm();
	testCreateShrubberyCreationForm();
	testCreateInvalidForm();
	return (0);
}
