#include "philo_one.h"

void	ft_putchar_fd(int c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= (-1);
	}
	if (i > 9)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putchar_fd(((i % 10) + 48), fd);
	}
	else
		ft_putchar_fd((i + '0'), fd);
}

int	main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Wrong number of arguments!\n", 27);
		return (1);
	}
	checkArgs(argv);
	checkNumbers(argv);
	startPhilo();
}
