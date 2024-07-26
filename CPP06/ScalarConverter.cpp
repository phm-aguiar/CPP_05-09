
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
	  *this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() { return; }

void ScalarConverter::convert(std::string input) {
	std::cout << "Convert " << input << std::endl;
	// try
	// {
	// 	int i = std::strtodi(input);
	// 	std::cout << "int: " << i << std::endl;
	// }
	// catch (std::exception &e)
	// {
	// 	std::cerr << "int: impossible" << std::endl;
	// }
  
}