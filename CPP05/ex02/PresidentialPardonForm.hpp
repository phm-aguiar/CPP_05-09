
#ifndef PRESIDENTIALPARDONFORM_HPP_
#define PRESIDENTIALPARDONFORM_HPP_
#include "AForm.hpp"

class AForm;
// Class declaration
class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
  ~PresidentialPardonForm();
  void execute(Bureaucrat const & executor) const;

 private:
	  std::string _target;
};

#endif // PRESIDENTIALPARDONFORM_HPP_
