/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 15:06:32 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/03 11:35:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void testPopulateArray(){
	Array<int> a(5);
	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout <<MAGENTA <<a[i] <<RESET<< " ";
	std::cout << std::endl;
}

void testDeepCopy(void)
{
	Array<int> a(5);
	a[0] = 21;
	Array<int> b(a);
	a[0] = 42;
	std::cout << MAGENTA << a[0] << RESET << std::endl;
	std::cout << MAGENTA << b[0] << RESET <<std::endl;
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

void testMethodSize(void)
{
	Array<int> a(5);
	std::cout << MAGENTA <<a.size() << RESET << std::endl;
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

void testCopyConstructor()
{
    std::cout <<YELLOW "Testing Copy Constructor" RESET<< std::endl;

    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = i + 1;
    Array<int> copy(original);
    copy[0] = 42;
    std::cout <<BLUE "Original array after modifying the copy: " RESET;
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << MAGENTA <<original[i] << " " << RESET;
    std::cout << std::endl;
    std::cout <<BLUE "Copy array: " RESET;
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << MAGENTA <<copy[i] << " "<< RESET;
    std::cout << std::endl;
}

void testAssignmentOperator()
{
    std::cout <<YELLOW "Testing Assignment Operator" RESET<< std::endl;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = i + 1;
    Array<int> other;
    other = original;
    other[0] = 42;
    std::cout << BLUE "Original array after modifying the other array: " RESET;
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << MAGENTA << original[i] << " " << RESET;
    std::cout << std::endl;

    std::cout <<BLUE "Other array: " RESET;
    for (unsigned int i = 0; i < other.size(); i++)
        std::cout << MAGENTA <<other[i] << " " << RESET;
    std::cout << std::endl;

	
}

void testAssignmentSmallerToLarger()
{
    std::cout <<YELLOW "Testing assignment of smaller array to larger array" RESET<< std::endl;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = i + 1;
    Array<int> subarray(3);
    for (unsigned int i = 0; i < subarray.size(); i++)
        subarray[i] = (i + 1) * 10;
    std::cout <<BLUE << "Subarray size before assignment: " << MAGENTA << subarray.size() << RESET<< std::endl;
    std::cout <<BLUE "Subarray values before assignment: " RESET;
    for (unsigned int i = 0; i < subarray.size(); i++)
        std::cout << MAGENTA <<subarray[i] << " " << RESET;
    std::cout << std::endl;
    std::cout << BLUE "Original array values: " RESET;
    for (unsigned int i = 0; i < original.size(); i++)
		std::cout << MAGENTA <<original[i] << " " << RESET;
    std::cout << std::endl;
    subarray = original;
	std::cout << BLUE "Subarray size after assignment: " RESET;
	std::cout << MAGENTA << subarray.size() << RESET << std::endl;
	std::cout << BLUE "Subarray values after assignment: " RESET;
	for (unsigned int i = 0; i < subarray.size(); i++)
		std::cout << MAGENTA <<subarray[i] << " " << RESET;
	std::cout << std::endl;
	
}


int	main(void)
{
	std::cout <<YELLOW "Testing Array class" RESET<< std::endl;
	std::cout <<YELLOW "Testing populate array" RESET<< std::endl;
	testPopulateArray();
	std::cout << std::endl;
	std::cout <<YELLOW "Testing deep copy" RESET<< std::endl;
	testDeepCopy();
	std::cout << std::endl;
	std::cout <<YELLOW "Testing empty array" RESET<< std::endl;
	testEmptyArray();
	std::cout << std::endl;
	std::cout <<YELLOW "Testing function size" RESET<< std::endl;
	testMethodSize();
	std::cout << std::endl;
	std::cout <<YELLOW "Testing negative index" RESET<< std::endl;
	testNegativeIndex();
	std::cout << std::endl;
	std::cout <<YELLOW "Testing index out of limits" RESET<< std::endl;
	testIndexOutOfLimits();
	std::cout << std::endl;
	testCopyConstructor();
	std::cout << std::endl;
	testAssignmentOperator();
	std::cout << std::endl;
	testAssignmentSmallerToLarger();
	std::cout << std::endl;
	return (0);
}
