#ifndef ITER_HPP
# define ITER_HPP

# include <algorithm>
# include <iostream>
# include <stdexcept>
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PINK "\033[1;35m"
# define RESET "\033[0m"

class Error404 : public std::exception
{
  public:
    virtual const char *what() const throw();
};

template <class T> typename T::iterator easyfind(T &contêiner, int valor) {
    if (contêiner.empty())
        throw Error404();
    typename T::iterator it = std::find(contêiner.begin(), contêiner.end(), valor);
    if (it == contêiner.end())
        throw Error404();
    return it;
}

#endif