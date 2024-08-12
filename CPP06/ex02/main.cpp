#include "Base.hpp"

void	ft_usleep(int time)
{
	clock_t	start;

	start = clock();
	while (clock() < start + time)
		;
}

int	main(void)
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test " << i << std::endl;
		Base *base = generate();

		identify(base);
		identify(*base);
		delete base;
		ft_usleep(1000000);
	}
	identify(NULL);
	return (0);
}