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
	std::cout << "RobotomyRequestForm test" << std::endl;
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

void	testShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm test" << std::endl;
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

	std::cout << "Testing file creation by ShrubberyCreationForm" << std::endl;
	ShrubberyCreationForm form("home");
	Bureaucrat b("Director", 1);
	form.beSigned(b);
	form.execute(b);
	std::ifstream file("home_shrubbery");
	fileExists = file.good();
	std::cout << MAGENTA << "File created: " << (fileExists ? "Yes" : "No") << RESET << std::endl;
}

void testShrubberyCreationDuplicateFile(void)
{
	std::cout << "Testing Duplicate file creation by ShrubberyCreationForm" << std::endl;
	ShrubberyCreationForm form("home");
	ShrubberyCreationForm form2("home");
	Bureaucrat b("Director", 1);
	form.beSigned(b);
	form.execute(b);
	form2.beSigned(b);
	form2.execute(b);
}

void testFormExecutionWithoutSignature() {
    std::cout << "Testando a execução de formulário não assinado" << std::endl;
    ShrubberyCreationForm form("garden");
    Bureaucrat b("Manager", 1);
    try {
        form.execute(b);
        std::cout << "Erro: Formulário não assinado foi executado." << std::endl;
    } catch (std::exception& e) {
        std::cout << "Sucesso: Tentativa de execução de formulário não assinado lançou exceção." << std::endl;
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
