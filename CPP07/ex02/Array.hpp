
#ifndef ARRAY_HPP_
# define ARRAY_HPP_
# include <iostream>
# include <stdexcept>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define RESET "\033[0m"
// Class declaration
template <typename T> class Array
{
  public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &rhs);
	T &operator[](unsigned int index);
	~Array();
	unsigned int size() const;
	class EmptyArrayException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class OutOfLimitsException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

  private:
	T *_array;
	unsigned int _size;
};
# include "Array.tpp"

#endif // ARRAY_HPP_
