
#ifndef FORM_HPP_
#define FORM_HPP_

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

// Class declaration
class Form {
 public:
  // canonical form
  Form();
  Form(const Form &other);
  Form &operator=(const Form &rhs);
  ~Form();
  // constructor with parameters
  Form(std::string name, int signGrade, int execGrade);
  
  //exception classes
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

	// getters
	const std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;

	// methods
	void beSigned(const Bureaucrat &bureaucrat);

 private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const Form &form);


#endif // FORM_HPP_
