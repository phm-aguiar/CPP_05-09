#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() : _exchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this != &rhs)
	{
		_exchange = rhs.getExchange();
	}
	return (*this);
}

void BitcoinExchange::printExchange()
{
	std::map<std::string, float>::iterator it = _exchange.begin();
	while (it != _exchange.end())
	{
		std::cout << GREEN << "key: " << it->first << RESET << std::endl
					<< RED "value: " << it->second << RESET << std::endl;
		it++;
	}
}

void BitcoinExchange::searchExchange(std::string key)
{
	 std::map<std::string, float>::iterator it = _exchange.upper_bound(key);

	it--;
	std::cout << key << " => " << _value << " = " << it->second * _value << std::endl;
	
}

std::map<std::string, float> BitcoinExchange::getExchange() const
{
	return (_exchange);
}

void BitcoinExchange::putExchange(std::string key, float value)
{
	_exchange[key] = value;
}

float BitcoinExchange::getValue() const
{
	return (_value);
}

void BitcoinExchange::setValue(float value)
{
	_value = value;
}
