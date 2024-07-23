#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testPresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm test" << std::endl;
	PresidentialPardonForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
	form.beSigned(b);
	std::cout << form << std::endl;
	form.execute(b);
	try
	{
		form.execute(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to execute document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void testRobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm test" << std::endl;
	RobotomyRequestForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
	form.beSigned(b);
	std::cout << form << std::endl;
	form.execute(b);
	try
	{
		form.execute(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to execute document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void testShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm test" << std::endl;
	ShrubberyCreationForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
	form.beSigned(b);
	std::cout << form << std::endl;
	form.execute(b);
	try
	{
		form.execute(b2);
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to execute document without grade required " << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	testPresidentialPardonForm();
	std::cout << std::endl;
	std::cout << std::endl;
	testRobotomyRequestForm();
	std::cout << std::endl;
	std::cout << std::endl;
	testShrubberyCreationForm();
	return (0);
}
