#include "philo_one.h"

void	locked_print(char	*str, int	id)
{
	t_philos	*container;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	printf("%lld %d %s", ft_getTime(), (id + 1), str);
	pthread_mutex_unlock(&container->writeMutex);
}

unsigned long long	ft_getTime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

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
		return (ft_error("Wrong number of arguments!\n"));
	if (checkArgs(argv))
		return (1);
	if (checkNumbers(argv))
		return (1);
	if (startPhilo())
		return (1);
	if (check_death())
		return (1);
	if (endPhilo())
		return (1);
	return (0);
}
