#ifndef BUREAUCRAT_HPP_
# define BUREAUCRAT_HPP_

# include "AForm.hpp"
# include <exception>
# include <iostream>

class	AForm;
// collors

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define RESET "\033[0m"
# define SEPBAR "\033[1;36m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\033[0m"

// Class declaration
class Bureaucrat
{
  public:
	// canonical form
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();
	// implementation specific methods
	Bureaucrat(std::string name, int grade);
	std::string getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signAForm(AForm &form);
	void executeForm(AForm const &form);

	// class specific exceptions
	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};

  private:
	std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP_
