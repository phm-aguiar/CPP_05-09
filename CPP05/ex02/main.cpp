#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testPresidentialPardonForm(void)
{
	std::cout << YELLOW << "PresidentialPardonForm test" << RESET << std::endl;
	PresidentialPardonForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
		try
		{
			form.execute(b2);
		}
		catch (std::exception &e)
		{
			std::cout << "test: attempt to execute document without grade required " << std::endl;
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << RED << e.what() << RESET << std::endl;
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
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	testRobotomyRequestForm(void)
{
	std::cout << YELLOW << "RobotomyRequestForm test" << RESET << std::endl;
	RobotomyRequestForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
		try
		{
			form.execute(b2);
		}
		catch (std::exception &e)
		{
			std::cout << "test: attempt to execute document without grade required " << std::endl;
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << YELLOW << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << RED << e.what() << RESET << std::endl;
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
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	testShrubberyCreationForm(void)
{
	std::cout << YELLOW << "ShrubberyCreationForm test" << RESET << std::endl;
	ShrubberyCreationForm form("test");
	Bureaucrat b("b", 1);
	Bureaucrat b2("b2", 150);
	std::cout << form << std::endl;
	try
	{
		form.beSigned(b2);
		try
		{
			form.execute(b2);
		}
		catch (const std::exception &e)
		{
			std::cout << "test: attempt to execute document without grade required " << std::endl;
			std::cerr << RED << e.what() << RESET << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "test: attempt to sign document without grade required " << std::endl;
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	form.beSigned(b);
	std::cout << form << std::endl;
	form.execute(b);
	try
	{
		form.execute(b2);
	}
	catch (const std::exception &e)
	{
		std::cout << "test: attempt to execute document without grade required " << std::endl;
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void	testShrubberyCreationFileCreation(void)
{
	bool	fileExists;

	std::cout << YELLOW << "Testing file creation by ShrubberyCreationForm" << RESET << std::endl;
	ShrubberyCreationForm form("home");
	Bureaucrat b("Director", 1);
	form.beSigned(b);
	form.execute(b);
	std::ifstream file("home_shrubbery");
	fileExists = file.good();
	std::cout << MAGENTA << "File created: " << (fileExists ? "Yes" : "No") << RESET << std::endl;
}

void	testShrubberyCreationDuplicateFile(void)
{
	std::cout << YELLOW << "Testing Duplicate file creation by ShrubberyCreationForm" << RESET << std::endl;
	ShrubberyCreationForm form("home");
	ShrubberyCreationForm form2("home");
	Bureaucrat b("Director", 1);
	form.beSigned(b);
	form.execute(b);
	form2.beSigned(b);
	form2.execute(b);
}

void	testFormExecutionWithoutSignature(void)
{
	std::cout << YELLOW << "Testing unsigned form execution" << RESET << std::endl;
	ShrubberyCreationForm form("garden");
	Bureaucrat b("Manager", 1);
	try
	{
		form.execute(b);
		std::cout << "Error: Unsigned form was executed." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Success: Attempt to execute an unsigned form threw an exception." << std::endl;
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
	std::cout << std::endl;
	std::cout << std::endl;
	testShrubberyCreationFileCreation();
	std::cout << std::endl;
	std::cout << std::endl;
	testShrubberyCreationDuplicateFile();
	std::cout << std::endl;
	std::cout << std::endl;
	testFormExecutionWithoutSignature();
	return (0);
}
