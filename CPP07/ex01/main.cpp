#include "Iter.hpp"

int	main(void)
{
	int intArray[] = {1, 2, 3, 4, 5};
	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArray[] = {"one", "two", "three", "four", "five"};

	std::cout << "intArray: ";
	iter(intArray, 5, print);
	std::cout << std::endl;
	std::cout << "doubleArray: ";
	iter(doubleArray, 5, print);
	std::cout << std::endl;
	std::cout << "stringArray: ";
	iter(stringArray, 5, print);
	std::cout << std::endl;
	std::cout << "invalid length; length = 0: ";
	iter(intArray, 0, print);
	std::cout << std::endl;
	std::cout << "invalid array; array = NULL: ";
	iter(static_cast<int *>(NULL), 5, print);
	std::cout << std::endl;
	std::cout << "invalid function; function = NULL: ";
	iter(intArray, 5, static_cast<void (*)(int const &)>(NULL));
	std::cout << std::endl;
	return (0);
}