
#ifndef SHRUBBERYCREATIONFORM_HPP_
# define SHRUBBERYCREATIONFORM_HPP_
# include "AForm.hpp"
# include <fstream>

class	AForm;

// Class declaration
class ShrubberyCreationForm : public AForm
{
  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;

  private:
	std::string _target;
};

#endif // SHRUBBERYCREATIONFORM_HPP_
