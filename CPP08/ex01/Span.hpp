/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:23:02 by phenriq2          #+#    #+#             */
/*   Updated: 2024/08/06 14:07:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP_
# define SPAN_HPP_

# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <stdexcept>
# include <vector>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PINK "\033[1;35m"
# define RESET "\033[0m"

// Class declaration
class Span
{
  public:
	Span();
	Span(unsigned int N);
	Span(const Span &other);
	Span &operator=(const Span &rhs);
	~Span();
	void addNumber(int number);
	unsigned int shortestSpan(void);
	unsigned int longestSpan(void);
	void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void printNumbers(void);
	unsigned int getSize(void);

  private:
	std::vector<int> _numbers;
	unsigned int _size;
};


#endif // SPAN_HPP_
