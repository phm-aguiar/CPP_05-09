
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target){}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if(this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

// Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException();
	if(!getSigned())
		throw FormNotSignedException();
	std::ofstream file;
	std::string name = _target + "_shrubbery";
	file.open(name.c_str());
	if(file.is_open())
	{
		file << "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n";
		file << "⠀⠀⠀⢀⣼⣦⠀⠀⣠⣿⣿⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣆⠀⠀⠀⠀⠀\n";
		file << "⠀⠀⠒⣿⣿⣿⠓⠀⠀⠻⣿⣿⠀⢀⣴⣿⣦⡀⠀⢀⣾⣦⠘⢿⣿⣧⡀⠀⠀⠀\n";
		file << "⠀⢀⣴⣿⡿⠃⡄⠈⠻⣿⣟⣉⣀⠉⣽⡿⠋⠡⠴⣿⣿⣿⠓⠀⠙⢇⠀⠀⠀⠀\n";
		file << "⠀⠿⣿⠟⢁⣾⣿⣦⣀⠘⠿⠟⢀⣼⣿⣿⣷⠂⣴⣿⣿⣿⣆⠘⢶⣶⣿⠶⠤⠀\n";
		file << "⠀⣀⣀⡀⢉⣿⣿⣿⡍⠀⢀⣀⠙⢻⠿⢋⣤⣾⣿⣿⣿⣿⣿⣷⣄⠙⢿⣦⡀⠀\n";
		file << "⠀⠟⠋⣠⣾⣿⣿⣿⣿⣦⣌⠉⠠⣤⣤⣤⡌⢙⣿⣿⣿⣿⣿⣿⠛⠛⠂⢈⣙⠀\n";
		file << "⠀⠀⣉⡉⣹⣿⣿⣿⣿⣏⠉⣉⣀⣈⠙⠋⣠⣿⣿⣿⣿⣿⣿⣿⣆⠙⠛⠛⠛⠀\n";
		file << "⠀⠀⠋⣴⣿⣿⣿⣿⣿⣿⣷⣌⠉⢁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠀⠀\n";
		file << "⠀⠴⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠦⠈⣙⠛⠛⠛⠛⠛⠛⠛⣉⣉⠁⠀⠀⠀\n";
		file << "⠀⠀⣦⣤⡄⢉⣉⣉⣉⠉⣡⣤⠀⠀⠀⣿⣿⣷⠀⢰⣿⣿⡇⢸⣿⣿⠀⠀⠀⠀\n";
		file << "⠀⠀⣿⣿⡇⣸⣿⣿⣿⡄⢻⣿⠀⠀⠀⣿⣿⣿⠀⢸⣿⣿⡇⢸⣿⣿⠀⠀⠀⠀\n";
		file << "⠀⠀⣿⣿⠁⣿⣿⣿⣿⡇⠸⠿⠀⠀⠀⣿⣿⣿⠀⢸⣿⣿⣇⠸⣿⣿⠀⠀⠀⠀\n";
		file << "⠀⠀⠛⠛⠀⣿⣿⣿⣿⡇⠀⠀⠀⠀⠀⠉⠉⠉⠀⢸⣿⣿⣿⠀⠿⠿⠀⠀⠀⠀\n";
		file << "⠀⠀⠀⠀⠀⠛⠛⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀\n";
		file.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}