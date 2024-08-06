/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:05:36 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/05 12:50:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <deque>
#include <list>
#include <vector>

void	testDeque(void)
{
	std::deque<int> d;
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(42);
	d.push_back(5);
	std::cout << GREEN "deque: " RESET;
	for (std::deque<int>::iterator it = d.begin(); it != d.end(); it++)
		std::cout << PINK << *it << " " << RESET;
	std::cout << std::endl;
	try
	{
		std::cout <<YELLOW "Finding 3" RESET<< std::endl;
		std::cout << BLUE << *easyfind(d, 3) << " Found" RESET<< std::endl;
		std::cout <<YELLOW "Finding 6" RESET<< std::endl;
		std::cout << *easyfind(d, 6) << std::endl;
	}
	catch (const Error404 &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testVector(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(42);
	v.push_back(5);
	std::cout << GREEN "vector: " RESET;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << PINK << *it << " " << RESET;
	std::cout << std::endl;
	try
	{
		std::cout <<YELLOW "Finding 3" RESET<< std::endl;
		std::cout << BLUE << *easyfind(v, 3) <<" Found" RESET<<  std::endl;
		std::cout <<YELLOW "Finding 6" RESET<< std::endl;
		std::cout << *easyfind(v, 6) << std::endl;
	}
	catch (const Error404 &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testList(void)
{
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(42);
	l.push_back(5);
	std::cout << GREEN "list: " RESET;
	for (std::list<int>::iterator it = l.begin(); it != l.end(); it++)
		std::cout << PINK << *it << " " << RESET;
	std::cout << std::endl;
	try
	{
		std::cout <<YELLOW "Finding 3" RESET<< std::endl;
		std::cout <<BLUE << *easyfind(l, 3) << " Found" RESET<< std::endl;
		std::cout <<YELLOW "Finding 6" RESET<< std::endl;
		std::cout << *easyfind(l, 6) << std::endl;
	}
	catch (const Error404 &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	try
	{
		testDeque();
		testVector();
		testList();
	}
	catch (const std::exception &e)
	{
		std::cout << "exception not caught" << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return (0);
}