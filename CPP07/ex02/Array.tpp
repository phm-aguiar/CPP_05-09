/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:43:18 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/02 17:13:55 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T> const char *Array<T>::EmptyArrayException::what() const throw()
{
	return (RED "cannot access an empty array" RESET);
}

template <typename T> const char *Array<T>::OutOfLimitsException::what() const throw()
{
	return (RED "index out of limits" RESET);
}

template <typename T> Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T> Array<T>::Array(unsigned int n) :  _size(n){
	if (n == 0)
		return ;
	_array = new T[n];
}

template <typename T> Array<T>::Array(const Array &other) : _array(NULL),
	_size(other._size)
{
	if (_size == 0)
		return ;
	delete[] _array;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = other._array[i];
}

template <typename T> Array<T> &Array<T>::operator=(const Array &rhs)
{
	if (this == &rhs)
		return (*this);
	if (_size > 0)
		delete[] _array;
	_array = new T[rhs._size];
	_size = rhs._size;
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = rhs._array[i];
	return (*this);
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (_size == 0)
		throw EmptyArrayException();
	if (index >= _size)
		throw OutOfLimitsException();
	return (_array[index]);
}

template <typename T> Array<T>::~Array(void)
{
	if (_size > 0)
		delete[] _array;
}

template <typename T> unsigned int Array<T>::size() const {return (_size);}