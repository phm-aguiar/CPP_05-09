#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Rpn
{
  public:
	Rpn();
	Rpn(Rpn const &src);
	~Rpn();

	Rpn &operator=(Rpn const &rhs);
	bool validateInput(std::string input);
	void rpn(std::string input);
	void printStack();
	std::stack<double> getStack() const;
	class InvalidExpression : public std::exception{
		virtual const char *what() const throw();
	};
  private:
	std::stack<double> _stack;
	bool isOperator(char c);
	bool isNumber(char c);
	double calculate(double a, double b, char c);

};

#endif