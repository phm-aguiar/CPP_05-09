/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:14:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/02 13:42:19 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// Função para testar a função swap
void	testSwap(void)
{
	int		a = 5, b = 10;
	double	x = 1.1, y = 2.2;

	std::cout << "a: " << a << " b: " << b << std::endl;
	swap(a, b);
	if (a == 10 && b == 5)
		std::cout << "swap(int) passou!" << std::endl;
	else
		std::cout << "swap(int) falhou!" << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << std::endl;
	std::cout << "x: " << x << " y: " << y << std::endl;
	swap(x, y);
	if (x == 2.2 && y == 1.1)
		std::cout << "swap(double) passou!" << std::endl;
	else
		std::cout << "swap(double) falhou!" << std::endl;
	std::cout << "x: " << x << " y: " << y << std::endl;
	std::cout << std::endl;
}

void	testMin(void)
{
	int		a = 3, b = 4;
	float	x = 5.5, y = 2.2;
	double	c = 3.3, d = 4.4;
	std::string s1 = "42", s2 = "42sp";
	
	if (min(a, b) == 3)
		std::cout << "min(int) passou!" << std::endl;
	else
		std::cout << "min(int) falhou!" << std::endl;
	if (min(x, y) == 2.2f)
		std::cout << "min(double) passou!" << std::endl;
	else
		std::cout << "min(double) falhou!" << std::endl;
	if (min(c, d) == 3.3)
		std::cout << "min(float) passou!" << std::endl;
	else
		std::cout << "min(float) falhou!" << std::endl;
	if (::min(s1, s2) == "42")
		std::cout << "min(string) passou!" << std::endl;
	else
		std::cout << "min(string) falhou!" << std::endl;
}

// Função para testar a função max
void	testMax(void)
{
	int		a = 3, b = 4;
	float	x = 5.5, y = 2.2;
	double	c = 3.3, d = 4.4;
	std::string s1 = "42", s2 = "42sp";

	if (max(a, b) == 4)
		std::cout << "max(int) passou!" << std::endl;
	else
		std::cout << "max(int) falhou!" << std::endl;
	if (max(x, y) == 5.5f)
		std::cout << "max(float) passou!" << std::endl;
	else
		std::cout << "max(float) falhou!" << std::endl;
	if (max(c, d) == 4.4)
		std::cout << "max(double) passou!" << std::endl;
	else
		std::cout << "max(double) falhou!" << std::endl;
	if (::max(s1, s2) == "42sp")
		std::cout << "max(string) passou!" << std::endl;
	else
		std::cout << "max(string) falhou!" << std::endl;
}

int	main(void)
{
	
	std::cout << "-=-=-=-=-=Swap test-=-=-=-=-=" << std::endl;
	testSwap();
	std::cout << std::endl;
	std::cout << "-=-=-=-=-=Min test-=-=-=-=-=" << std::endl;
	testMin();
	std::cout << std::endl;
	std::cout << "-=-=-=-=-=Max test-=-=-=-=-=" << std::endl;
	testMax();
	return (0);
}

// int main( void ) 
// {
// 	int a = 2;
// 	int b = 3;
// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }
