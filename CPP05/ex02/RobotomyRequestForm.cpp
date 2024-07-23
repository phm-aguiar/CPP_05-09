
#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << YELLOW << "Default constructor called" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
  _target = target;
  std::cout << YELLOW << "RobotomyRequestForm constructor called" << RESET << std::endl;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

// Copy assignment overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if(this != &rhs)
  {
    AForm::operator=(rhs);
    _target = rhs._target;
  }
	return (*this);
}

// Default destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << YELLOW << "Default destructor called" << RESET << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() > getExecGrade())
    throw GradeTooLowException();
  if(!getSigned())
    throw FormNotSignedException();

  std::cout<<"*drilling noises* ";
  std::srand(std::time(0));
  if (std::rand() % 2)
    std::cout << _target << " has been robotomized successfully" << std::endl;
  else
    std::cout << _target << " robotomization failed" << std::endl;
}
