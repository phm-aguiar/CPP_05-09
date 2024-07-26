#include "Bureaucrat.hpp"

void testFailIncrementGrade(void)
{
	std::cout << MAGENTA "Fail IncrementGrade test" RESET << std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	try
	{
		b.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout <<RED<< b <<RESET<< std::endl;
}

void testFailDecrementGrade(void)
{
	std::cout << MAGENTA "Fail DecrementGrade test" RESET << std::endl;
	Bureaucrat b("b", 150);
	std::cout << b << std::endl;
	try
	{
		b.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout <<RED<< b <<RESET <<std::endl;
}

void testIncrementGrade(void)
{
	std::cout << MAGENTA "IncrementGrade test" RESET << std::endl;
	Bureaucrat b("b", 150);
	std::cout << b << std::endl;
	try
	{
		b.incrementGrade();
		std::cout << "Incremented" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << b << RESET <<std::endl;
}

void testDecrementGrade(void)
{
	std::cout <<MAGENTA "DecrementGrade test" RESET<< std::endl;
	Bureaucrat b("b", 1);
	std::cout << b << std::endl;
	try
	{
		b.decrementGrade();
		std::cout << "Decremented" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << GREEN << b << RESET <<std::endl;
}

void testInvalidGrade(void)
{
	std::cout <<MAGENTA "Invalid Grade test" RESET<< std::endl;
	try
	{
		Bureaucrat b("b", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	try
	{
		Bureaucrat b("b", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

void testValidGrade(void)
{
	std::cout <<MAGENTA "Valid Grade test" RESET<< std::endl;
	Bureaucrat b("b", 1);
	std::cout << GREEN << b << RESET <<std::endl;
	Bureaucrat b2("b2", 150);
	std::cout << GREEN << b2 << RESET <<std::endl;
}


int main(void){
	testInvalidGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	testValidGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	testFailIncrementGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	testFailDecrementGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	testIncrementGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	testDecrementGrade();
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}