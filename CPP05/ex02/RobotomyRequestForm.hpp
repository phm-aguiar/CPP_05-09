
#ifndef ROBOTOMYREQUESTFORM_HPP_
# define ROBOTOMYREQUESTFORM_HPP_
# include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class	AForm;
// Class declaration
class RobotomyRequestForm : public AForm
{
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();
	void execute(Bureaucrat const &executor) const;

  private:
	std::string _target;
};

#endif // ROBOTOMYREQUESTFORM_HPP_
