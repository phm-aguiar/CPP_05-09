
#ifndef INTERN_HPP_
#define INTERN_HPP_

#include "AForm.hpp"

class AForm;


enum FormType
{
	PRESIDENTIALPARDON,
	ROBOTOMYREQUEST,
	SHRUBBERYCREATION
};

class Intern  {
 public:
  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &rhs);
  ~Intern();

  AForm *makeForm(std::string formName, std::string target);

  class FormNotFoundException : public std::exception
  {
	public:
	virtual const char *what(void) const throw();
  };

 private:
  
};

#endif // INTERN_HPP_
