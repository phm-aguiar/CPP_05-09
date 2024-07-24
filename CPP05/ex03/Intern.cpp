
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &other)
{
	*this = other;
}

Intern &Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern(){}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[4] = {"presidential pardon", "robotomy request", "shrubbery creation", "Default"};
	int i = 0;
	while(i < 4)
	{
		if (formName == formNames[i])
			break ;
		i++;
	}
	switch (i)
	{
		case PRESIDENTIALPARDON:
			std::cout << "Intern creates " << formName << std::endl;
			return (new PresidentialPardonForm(target));
		case ROBOTOMYREQUEST:
			std::cout << "Intern creates " << formName << std::endl;
			return (new RobotomyRequestForm(target));
		case SHRUBBERYCREATION:
			std::cout << "Intern creates " << formName << std::endl;
			return (new ShrubberyCreationForm(target));
		default:
			throw Intern::FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what(void) const throw()
{
	return ("Form not found");
}