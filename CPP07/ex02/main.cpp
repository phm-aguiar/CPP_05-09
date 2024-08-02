/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:06:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/02 17:14:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void testPopulateArray(){
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

void testDeepCopy(void)
{
	Array<int> a(5);
	a[0] = 21;
	Array<int> b(a);
	a[0] = 42;
	std::cout << a[0] << std::endl;
	std::cout << b[0] << std::endl;
}

void testEmptyArray(void)
{
	Array<int> a;
	try
	{
		std::cout << a[0] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testFunctionSize(void)
{
	Array<int> a(5);
	std::cout << a.size() << std::endl;
}

void testNegativeIndex(void)
{
	Array<int> a(5);
	try
	{
		std::cout << a[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void testIndexOutOfLimits(void)
{
	Array<int> a(5);
	try
	{
		std::cout << a[5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	testPopulateArray();
	std::cout << std::endl;
	testDeepCopy();
	std::cout << std::endl;
	testEmptyArray();
	std::cout << std::endl;
	testFunctionSize();
	std::cout << std::endl;
	testNegativeIndex();
	std::cout << std::endl;
	testIndexOutOfLimits();
	return (0);
}