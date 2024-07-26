
#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter() { return; }

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
  return;
}

// Copy assignment overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

// Default destructor
ScalarConverter::~ScalarConverter() { return; }

