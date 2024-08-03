#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <class T>
void	easyfind(T &param, int n)
{
	T::iterator it = std::find(param.begin(), param.end(), n);
	if (it == param.end())
		throw std::exception();
	else
		std::cout << "Found: " << *it << std::endl;
}



#endif