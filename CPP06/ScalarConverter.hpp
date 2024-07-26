
#ifndef SCALARCONVERTER_HPP_
# define SCALARCONVERTER_HPP_
# include <iostream>
// Class declaration
class ScalarConverter
{
  public:
	static void convert(std::string input);

  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &rhs);
	~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP_
