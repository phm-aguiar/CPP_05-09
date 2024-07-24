#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testCreateForm(int signGrade, int execGrade)
{
	try
	{
		Form f("f", signGrade, execGrade);
		std::cout << GREEN << f << RESET << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	testSingForm(void)
{
	Bureaucrat b("b", 1);
	Form f("f", 1, 1);
	std::cout << f << std::endl;
	std::cout << b << std::endl;
	try
	{
		b.signForm(f);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << f << RESET <<std::endl;
}

void	testFailSingForm(void)
{
	Bureaucrat b("b", 150);
	Form f("f", 1, 1);
	std::cout << f << std::endl;
	std::cout << b << std::endl;
	try
	{
		b.signForm(f);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	// std::cout << f << std::endl;
}

int	main(void)
{
	testCreateForm(0, 0);
	testCreateForm(151, 151);
	testCreateForm(1, 151);
	testCreateForm(151, 1);
	testCreateForm(0, 1);
	testCreateForm(1, 0);
	testCreateForm(0, 150);
	testCreateForm(150, 0);
	testCreateForm(150, 150);
	std::cout << std::endl;
	std::cout << std::endl;

	testFailSingForm();
	std::cout << std::endl;
	std::cout << std::endl;
	testSingForm();
	return (0);
}