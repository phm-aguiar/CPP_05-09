
#ifndef SERIALIZER_HPP_
# define SERIALIZER_HPP_
# include "Data.hpp"
# include <iostream>
# include <stdint.h>
// Class declaration
class Serializer
{
  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

  private:
	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &rhs);
	~Serializer();
};

#endif // SERIALIZER_HPP_
