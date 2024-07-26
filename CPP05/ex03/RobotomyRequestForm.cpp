
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if (!getSigned())
		throw FormNotSignedException();
	std::cout << BLUE << "*drilling noises* "<< RESET;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << GREEN << _target << " has been robotomized successfully" << RESET << std::endl;
	else
		std::cout << RED << _target << " robotomization failed" << RESET << std::endl;
}
