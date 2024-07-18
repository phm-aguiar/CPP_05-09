#include "Bureaucrat.hpp"

int printTestMsg(Bureaucrat &b, std::string msg){
	std::cout << SEPBAR << std::endl;
	std::cout << RED << msg << RESET << std::endl;
	std::cout << b << std::endl;
	std::cout << SEPBAR << std::endl;
	std::cout << std::endl;
	return (0);
}


int main(void){
	Bureaucrat b1;
	printTestMsg(b1, "Test default constructor");
	Bureaucrat b2("b2", 1);
	printTestMsg(b2, "Test constructor with parameters");
	std::cout << GREEN << "This is a exception message: " << RESET;
	Bureaucrat b3("b3", 0);
	printTestMsg(b3, "Test GradeTooHighException(grade -42 = Error)");
	std::cout << GREEN << "This is a exception message: " << RESET;
	Bureaucrat b4("b4", 151);
	printTestMsg(b4, "Test GradeTooLowException(grade -42 = Error)");
	Bureaucrat b5(b2);
	printTestMsg(b5, "Test copy constructor");
	Bureaucrat b6;
	b6 = b2;
	printTestMsg(b6, "Test copy assignment overload");
	b6.decrementGrade();
	printTestMsg(b6, "Test Valid decrementGrade");
	b2.incrementGrade();
	printTestMsg(b2, "Test incrementGrade");
	Bureaucrat b7("b7", 150);
	b7.decrementGrade();
	printTestMsg(b7, "Test decrementGrade");
	return (0);
}