#include "Bureaucrat.hpp"
#include "Form.hpp"

int	printTestMsg(Bureaucrat &b, std::string msg)
{
	std::cout << SEPBAR << std::endl;
	std::cout << RED << msg << RESET << std::endl;
	std::cout << b << std::endl;
	std::cout << SEPBAR << std::endl;
	std::cout << std::endl;
	return (0);
}

void	testForm(int signGrade, int execGrade)
{
	try
	{
		Form f("f", signGrade, execGrade);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}


int	main(void)
{
	Form f1;
	Form f2("Approval of nuclear attack.", 1, 1);
	Form f3("proof of transaction", 100, 100);
	Bureaucrat b2("b2", 1);
	printTestMsg(b2, "Test constructor with parameters");
	std::cout << GREEN << "This is a exception message: " << RESET;
	Bureaucrat b3("b3", 0);
	printTestMsg(b3, "Test GradeTooHighException(grade -42 = Error)");
	std::cout << GREEN << "This is a exception message: " << RESET;
	Bureaucrat b4("b4", 151);
	printTestMsg(b4, "Test GradeTooLowException(grade -42 = Error)");
	testForm(0, 0);
	testForm(151, 151);
	testForm(1, 151);
	testForm(151, 1);
	testForm(0, 1);
	testForm(1, 0);
	testForm(0, 150);
	testForm(150, 0);
	testForm(150, 150);
	Bureaucrat b5("b5", 10);
	std::cout << f2 << std::endl;
	b5.signForm(f2);
	std::cout << f3 << std::endl;
	b2.signForm(f3);
	return (0);
}