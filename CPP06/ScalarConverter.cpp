
#include "ScalarConverter.hpp"

static bool		ftStrIsNumber(const std::string &str);
static bool		ftStrIsLiteral(const std::string &str);
static void		ftValidateInput(const std::string &input);
static void		toChar(const std::string &conv);
static void		toInt(const std::string &conv);
static void		toFloat(const std::string &conv);
static void		toDooble(const std::string &conv);

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string input)
{
	try
	{
		ftValidateInput(input);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	try
	{
		std::cout << "char:   ";
		toChar(input);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "int:    ";
		toInt(input);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "float:  ";
		toFloat(input);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "double: ";
		toDooble(input);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const char *ScalarConverter::ImpossibleException::what() const throw()
{
	return (RED "impossible" RESET);
}

const char *ScalarConverter::NonDisplayableException::what() const throw()
{
	return (RED "Non displayable" RESET);
}

const char *ScalarConverter::InvalidInputException::what() const throw()
{
	return (RED "Invalid input" RESET);
}

static bool	ftStrIsNumber(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f'
			&& str[i] != '-' && str[i] != '+')
			return (false);
	}
	return (true);
}

static bool	ftStrIsLiteral(const std::string &str)
{
	if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf"
		|| str == "-inff" || str == "+inff" || str == "nanf")
		return (true);
	return (false);
}

static bool	ftStrIsChar(const std::string &str)
{
	if (str.length() == 1 && !std::isdigit(str[0]))
		return (true);
	return (false);
}

static void	ftValidateInput(const std::string &input)
{
	if (input.empty())
		throw ScalarConverter::InvalidInputException();
	if (!ftStrIsNumber(input) && !ftStrIsLiteral(input) && !ftStrIsChar(input))
		throw ScalarConverter::InvalidInputException();
}

static double	convertToDouble(const std::string &conv)
{
	if (ftStrIsChar(conv))
	{
		return (static_cast<double>(conv[0]));
	}
	return (std::strtod(conv.c_str(), NULL));
}

static void	toChar(const std::string &conv)
{
	double	d;

	d = convertToDouble(conv);
	if (d < MIN_INT || d > MAX_INT)
		throw ScalarConverter::ImpossibleException();
	if (std::isnan(d) || std::isinf(d))
		throw ScalarConverter::ImpossibleException();
	if (d < 0 || d > 127)
		throw ScalarConverter::ImpossibleException();
	if (d < 32 || d > 126)
		throw ScalarConverter::NonDisplayableException();
	std::cout << static_cast<char>(d) << std::endl;
}

static void	toInt(const std::string &conv)
{
	double	d;

	d = convertToDouble(conv);
	if (d < MIN_INT || d > MAX_INT)
		throw ScalarConverter::ImpossibleException();
	if (std::isnan(d) || std::isinf(d))
		throw ScalarConverter::ImpossibleException();
	std::cout << static_cast<int>(d) << std::endl;
}

static void	toFloat(const std::string &conv)
{
	double	d;

	d = convertToDouble(conv);
	if (std::isnan(d))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	else if (std::isinf(d))
	{
		if (d < 0)
			std::cout << "-inff" << std::endl;
		else
			std::cout << "+inff" << std::endl;
		return ;
	}
	if (d < MIN_INT || d > MAX_INT)
		throw ScalarConverter::ImpossibleException();
	if (d == static_cast<int>(d))
		std::cout << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << static_cast<float>(d) << "f" << std::endl;
}

static void	toDooble(const std::string &conv)
{
	double	d;

	d = convertToDouble(conv);
	if (std::isnan(d))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	else if (std::isinf(d))
	{
		if (d < 0)
			std::cout << "-inf" << std::endl;
		else
			std::cout << "+inf" << std::endl;
		return ;
	}
	if (d < MIN_INT || d > MAX_INT)
		throw ScalarConverter::ImpossibleException();
	if (d == static_cast<int>(d))
		std::cout << static_cast<double>(d) << ".0" << std::endl;
	else
		std::cout << static_cast<double>(d) << std::endl;
}
