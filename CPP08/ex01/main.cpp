/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:45:48 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/05 19:08:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

static void	ft_usleep(int time)
{
	clock_t	start;

	start = clock();
	while (clock() < start + time)
		;
}

void	testAddRange(void)
{
	Span s(5);
	std::vector<int> v;
	ft_usleep(1000000);
	srand(time(NULL));
	std::cout <<YELLOW "=-=-=-=-testAddRange-=-=-=-=" RESET<< std::endl;
	for (int i = 0; i < 5; i++)
		v.push_back(rand() % 100);
	std::cout <<BLUE "vector: " GREEN;
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	s.addRange(v.begin(), v.end());
	std::cout <<BLUE "span: ";
	s.printNumbers();
}

void testFailAddRange(void){
	Span s(1);
	std::vector<int> v;
	ft_usleep(1000000);
	std::cout <<YELLOW "=-=-=-=-testFailAddRange-=-=-=-=" RESET<< std::endl;
	v.push_back(42);
	v.push_back(41);
	v.push_back(40);
	try
	{
		std::cout <<BLUE "span size: " GREEN<< s.getSize() << std::endl;
		std::cout <<BLUE "vector size: " GREEN<< v.size() << std::endl;
		std::cout <<PINK "addRange() TEST: " RESET<< std::endl;
		s.addRange(v.begin(), v.end());
	}
	catch (const std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testLongestSpan(void)
{
	Span s(5);
	ft_usleep(1000000);
	srand(time(NULL));
	std::cout <<YELLOW "=-=-=-=-testLongestSpan-=-=-=-=" RESET<< std::endl;
	for (int i = 0; i < 5; i++)
		s.addNumber(rand() % 100);
	s.printNumbers();
	std::cout <<BLUE "Longest span: " GREEN<< s.longestSpan() << std::endl;
}

void testFailLongestSpan(void)
{
	Span s(1);
	ft_usleep(1000000);
	std::cout <<YELLOW "=-=-=-=-testFailLogestSpan-=-=-=-=" RESET<< std::endl;
	s.addNumber(42);
	try
	{
		std::cout <<BLUE "size: " GREEN<< s.getSize() << std::endl;
		std::cout <<PINK "longestSpan() TEST: " RESET<< std::endl;
		std::cout <<YELLOW "attempt to compare a span with just one number." RESET<< std::endl;
		s.longestSpan();
	}
	catch (const std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testShortestSpan(void)
{
	Span s(5);
	ft_usleep(1000000);
	srand(time(NULL));
	std::cout <<YELLOW "=-=-=-=-testShortestSpan-=-=-=-=" RESET<< std::endl;
	for (int i = 0; i < 5; i++)
		s.addNumber(rand() % 100);
	s.printNumbers();
	std::cout <<BLUE "Shortest span: " GREEN<< s.shortestSpan() << std::endl;
}

void testFailShortestSpan(void)
{
	Span s(1);
	ft_usleep(1000000);
	std::cout <<YELLOW "=-=-=-=-testFailShortestSpan-=-=-=-=" RESET<< std::endl;
	s.addNumber(42);
	try
	{
		std::cout <<BLUE "size: " GREEN<< s.getSize() << std::endl;
		std::cout <<PINK "shortestSpan() TEST: " RESET<< std::endl;
		std::cout <<YELLOW "attempt to compare a span with just one number." RESET<< std::endl;
		s.shortestSpan();
	}
	catch (const std::logic_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	testAddNumber(void)
{
	Span s(5);
	ft_usleep(1000000);
	srand(time(NULL));
	std::cout <<YELLOW "=-=-=-=-testAddNumber-=-=-=-=" RESET<< std::endl;
	for (int i = 0; i < 5; i++)
		s.addNumber(rand() % 100);
	s.printNumbers();
}

void testFaillAddNumber(void)
{
	Span s(1);
	ft_usleep(1000000);
	std::cout <<YELLOW "=-=-=-=-testFaillAddNumber-=-=-=-=" RESET<< std::endl;
	s.addNumber(42);
	try
	{
		std::cout <<BLUE "size: " GREEN<< s.getSize() << std::endl;
		std::cout <<PINK "addNumber() TEST: " RESET<< std::endl;
		std::cout <<YELLOW "attempt to add one more number" RESET<< std::endl;
		s.addNumber(41);
	}
	catch (const std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test10000Numbers(){
	Span s(10000);
	ft_usleep(1000000);
	std::cout <<YELLOW "=-=-=-=-test10000Numbers-=-=-=-=" RESET<< std::endl;
	for (int i = 0; i < 10000; i++)
		s.addNumber(rand() % 1000000);
	std::cout <<BLUE "Longest span: " GREEN<< s.longestSpan() << std::endl;
	std::cout <<BLUE "Shortest span: " GREEN<< s.shortestSpan() << std::endl;
}

int	main(void)
{
	testAddNumber();
	std::cout << std::endl;
	testFaillAddNumber();
	std::cout << std::endl;
	testShortestSpan();
	std::cout << std::endl;
	testFailShortestSpan();
	std::cout << std::endl;
	testLongestSpan();
	std::cout << std::endl;
	testFailLongestSpan();
	std::cout << std::endl;
	testAddRange();
	std::cout << std::endl;
	testFailAddRange();
	std::cout << std::endl;
	test10000Numbers();
	return (0);
}