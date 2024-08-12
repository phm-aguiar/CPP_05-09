#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <string>
# include <limits>
# include <cstdlib>
# include <sstream>
# include <exception>

# define YELLOW "\033[33m"
# define GREEN "\033[32m"
# define RED "\033[31m"
# define RESET "\033[0m"

class BitcoinExchange
{
  public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange();

	BitcoinExchange &operator=(BitcoinExchange const &rhs);
	std::map<std::string, float> getExchange() const;
	float getValue() const;
	void printExchange();
	void putExchange(std::string key, float value);
	void searchExchange(std::string key);
	void setValue(float value);


  private:
	std::map<std::string, float> _exchange;
	float _value;
};
#endif
