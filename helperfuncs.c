#include "philo_one.h"

t_philos	*statlist(void)
{
	static t_philos	ret;

	return (&ret);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	isAllNumber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;

	i = 0;
	num = 0;
	while (str[i])
	{
		num = (num * 10) + str[i] - '0';
		i++;
	}
	return (num);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit (1);
}
