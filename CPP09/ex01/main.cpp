/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 10:36:19 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/07 15:13:27 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"
#include <iostream>

void	tryInput(std::string input)
{
	Rpn	Rpn;

	std::cout << YELLOW "Input: " << input << RESET << std::endl;
	if (Rpn.validateInput(input))
		std::cout << GREEN "Valid input" RESET << std::endl;
	else
		std::cout << RED "Invalid input" RESET << std::endl;
	std::cout << std::endl;
}

void	testValidateInput(void)
{
	Rpn	Rpn;

	std::string input = "5 3 +";
	tryInput(input);
	input = "5 3     +5 - ";
	tryInput(input);
	input = "5 3 + 4 -";
	tryInput(input);
	input = "5 3 + 4 - 2";
	tryInput(input);
	input = "5 3 + 4 - 2 *";
	tryInput(input);
	input = "5 3 + 4 - 2 * 1";
	tryInput(input);
	input = "5 3 + 4 - 2 * 1 /";
	tryInput(input);
	input = "5 3 + 4 - 2 * 1 / 3";
	tryInput(input);
	input = "5 3 + 4 4";
	tryInput(input);
	input = "5 3 + 4 + 4 A";
	tryInput(input);
}

void	tryrpn(std::string input)
{
	Rpn	Rpn;

	try
	{
		Rpn.rpn(input);
		std::cout << YELLOW "Input: " << input << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	Rpn.printStack();
}

void	testrpn(void)
{
	std::string input = "5 3 +";
	tryrpn(input);
	input = "5 3     +5";
	tryrpn(input);
	input = "5 3 + 4 -";
	tryrpn(input);
	std::cout << std::endl;
	input = "5 3 + 4 - 2";
	tryrpn(input);
	input = "5 3 + 4 - 2 *";
	tryrpn(input);
	input = "5 3 + 4 - 2 * 1";
	tryrpn(input);
	input = "5 3 + 4 - 2 * 1 /";
	tryrpn(input);
	input = "5 3 + 4 - 2 * 1 / 3";
	tryrpn(input);
	std::cout << std::endl;
	std::cout << YELLOW "Subject tests" RESET << std::endl;
	std::cout << std::endl;
	input = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	tryrpn(input);
	input = "7 7 * 7 -";
	tryrpn(input);
	input = "1 2 * 2 / 2 * 2 4 - +";
	tryrpn(input);
	input = "(1 + 1)";
	tryrpn(input);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./Rpn \"5 3 +\"" << std::endl;
		return (1);
	}
// 	std::cout << "Testing validateInput" << std::endl;
// 	testValidateInput();
// 	std::cout << "Testing Rpn" << std::endl;
// 	testrpn();
	Rpn rpn;
	try
	{
		rpn.rpn(argv[1]);
		rpn.printStack();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}