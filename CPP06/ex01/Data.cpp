
#include "Data.hpp"

Data::Data() : _data(0), _str("default"){}

Data::Data(int data, std::string str) : _data(data), _str(str){}

Data::Data(const Data &other)
{
	*this = other;
}

Data &Data::operator=(const Data &rhs)
{
	if(this != &rhs)
  {
    this->_data = rhs._data;
    static_cast<std::string> (this->_str) = rhs._str;
  }
	return (*this);
}

Data::~Data(){}

int Data::getData() const
{
  return (this->_data);
}

std::string Data::getStr() const
{
  return (this->_str);
}