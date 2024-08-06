
#include "Span.hpp"

Span::Span()
{
	_numbers.reserve(0);
	_size = 0;
}

Span::Span(unsigned int N)
{
	_numbers.reserve(N);
	_size = N;
}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
		_size = rhs._size;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
	if (_size == _numbers.size())
		throw std::overflow_error(RED "Span::addNumber: no space left" RESET);
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void)
{
	int	min;

	if (_numbers.size() < 2)
		throw std::logic_error(RED "Span::shortestSpan: no numbers to compare" RESET);
	std::sort(_numbers.begin(), _numbers.end());
	min = _numbers[1] - _numbers[0];
	for (size_t i = 1; i < _numbers.size(); i++)
		if (_numbers[i] - _numbers[i - 1] < min)
			min = _numbers[i] - _numbers[i - 1];
	return (min);
}

unsigned int Span::longestSpan(void)
{
	unsigned int	max;

	if (_numbers.size() < 2)
		throw std::logic_error(RED "Span::longestSpan: no numbers to compare" RESET);
	std::sort(_numbers.begin(), _numbers.end());
	max = _numbers[_numbers.size() - 1] - _numbers[0];
	return (max);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin != end)
	{
		addNumber(*begin);
		begin++;
	}
}

void Span::printNumbers(void)
{
	std::cout << GREEN;
	for (size_t i = 0; i < _numbers.size(); i++)
		std::cout << _numbers[i] << " ";
	std::cout << std::endl;
}

unsigned int Span::getSize(void)
{
	return (_size);
}
