
#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_
# include <cmath>
# include <cstdlib> // Para atoi, atof
# include <iostream>
# include <limits>
# include <string>
# define FLOAT_CONV std::strtof
# define DOUBLE_CONV std::strtod
# define INT_CONV std::strtol
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET "\033[0m"
# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
class ScalarConverter
{
  public:
	static void convert(std::string input);

	class ImpossibleException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NonDisplayableException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class InvalidInputException : public std::exception
	{
		virtual const char *what() const throw();
	};

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
};



#endif // SCALARCONVERTER_HPP_
