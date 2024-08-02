#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T> void iter(T *array, size_t size,
	void (*function)(T const &))
{
	if (!array || !function)
	{
		std::cerr << "Error: invalid array or function" << std::endl;
		return ;
	}
	for (size_t i = 0; i < size; i++)
		function(array[i]);
}

template <typename T> void print(T const &i)
{
	std::cout << i << " ";
}

#endif