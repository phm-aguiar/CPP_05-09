#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include "Base.hpp"

Base::~Base(){}

Base	*generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
	{
		std::cout << RED "A instance of A has been created" RESET << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout <<GREEN "A instance of B has been created" RESET << std::endl;
		return (new B);
	}
	else
	{
		std::cout << MAGENTA "A instance of C has been created" RESET << std::endl;
		return (new C);
	}
}

std::string collors[5] ={RED, GREEN, YELLOW, BLUE, MAGENTA};

void	identify(Base *p)
{
	std::cout << collors[rand() % 5] << "identify(Base *p): ";
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	std::cout << collors[rand() % 5] << "identify(Base &p): ";
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "Unknown" << std::endl;
			}
		}
	}
}
