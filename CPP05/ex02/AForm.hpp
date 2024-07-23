
#ifndef AFORM_HPP_
#define AFORM_HPP_

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

// Class declaration
class AForm {
 public:
  // canonical Aform
  AForm();
  AForm(const AForm &other);
  AForm &operator=(const AForm &rhs);
  virtual ~AForm();
  // constructor with parameters
  AForm(std::string name, int signGrade, int execGrade);
  
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
	class FormNotSignedException : public std::exception
	{
		public:
		virtual const char *what(void) const throw();
	};
	// getters
	const std::string getName(void) const;
	bool getSigned(void) const;
	int getSignGrade(void) const;
	int getExecGrade(void) const;
	virtual void execute(Bureaucrat const & executor) const = 0;

	// methods
	void beSigned(const Bureaucrat &bureaucrat);

 private:
	const std::string _name;
	bool _signed;
	const int _signGrade;
	const int _execGrade;
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);


#endif // AFORM_HPP_
