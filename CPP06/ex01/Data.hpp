
#ifndef DATA_HPP_
# define DATA_HPP_
# include <iostream>
# include <string>
// Class declaration

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PINK "\033[35m"
# define RESET "\033[0m"

class Data
{
  public:
	Data();
	Data(int data, std::string str);
	Data(const Data &other);
	Data &operator=(const Data &rhs);
	~Data();
	int getData() const;
	std::string getStr() const;

  private:
	int _data;
	const std::string _str;
};

#endif // DATA_HPP_
