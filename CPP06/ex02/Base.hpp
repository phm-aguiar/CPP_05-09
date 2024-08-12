#ifndef BASE_HPP_
# define BASE_HPP_
# include <cstdlib>
# include <ctime>
# include <iostream>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"

class Base
{
  public:
	virtual ~Base();
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
