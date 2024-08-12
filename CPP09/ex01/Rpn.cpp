#include "Rpn.hpp"

bool Rpn::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool Rpn::isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool Rpn::validateInput(std::string input)
{
	std::string::iterator it = input.begin();
	while (it != input.end())
	{
		if (isNumber(*it))
		{
			std::string::iterator it2 = it;
			it2++;
			if (isNumber(*it2))
				return (false);
			std::string number(it, it2);
			it = it2;
		}
		else if (isOperator(*it))
			;
		else if (*it == ' ')
			;
		else
			return (false);
		if (it == input.end())
			return (false);
		it++;
	}
	return (true);
}

double Rpn::calculate(double a, double b, char c)
{
	if (c == '+')
		return (a + b);
	if (c == '-')
		return (a - b);
	if (c == '*')
		return (a * b);
	if (c == '/')
		return (a / b);
	return (0);
}

void Rpn::rpn(std::string input)
{
	double	a;
	double	b;
	double	result;

	if (!validateInput(input))
		throw InvalidExpression();
	std::string::iterator it = input.begin();
	while (it != input.end())
	{
		if (isNumber(*it))
		{
			std::string::iterator it2 = it;
			it2++;
			std::string number(it, it2);
			_stack.push(std::strtod(number.c_str(), NULL));
			it = it2;
		}
		else if (isOperator(*it))
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			result = calculate(a, b, *it);
			_stack.push(result);
		}
		it++;
	}
	if (_stack.size() != 1)
		throw InvalidExpression();
}

std::stack<double> Rpn::getStack() const
{
	return (_stack);
}

const char *Rpn::InvalidExpression::what() const throw()
{
	return (RED "Invalid expression" RESET);
}

void Rpn::printStack()
{
	std::stack<double> stack = getStack();
	while (!stack.empty())
	{
		std::cout << GREEN << stack.top() << RESET << std::endl;
		stack.pop();
	}
}

//  canonic ortodox

Rpn::Rpn() : _stack()
{
}

Rpn::Rpn(Rpn const &src)
{
	*this = src;
}

Rpn::~Rpn()
{
}

Rpn &Rpn::operator=(Rpn const &rhs)
{
	if (this != &rhs)
	{
		_stack = rhs.getStack();
	}
	return (*this);
}