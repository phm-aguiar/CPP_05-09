
#ifndef FORM_HPP_
# define FORM_HPP_

# include "Bureaucrat.hpp"
# include <exception>
# include <iostream>

class	Bureaucrat;

class Form
{
  public:
	Form();
	Form(const Form &other);
	Form &operator=(const Form &rhs);
	~Form();
	Form(std::string name, int signGrade, int execGrade);
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
	const std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	void beSigned(const Bureaucrat &bureaucrat);
  private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP_
