#include "philo_one.h"

int	checkArgs(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!isAllNumber(argv[i]))
		{
			write(2, "Not a valid argument\n", 21);
			return (1);
		}
		i++;
	}
	return (0);
}

int	checkNumbers(char **argv)
{
	t_philos	*container;

	container = statlist();
	container->philo_num = ft_atoi(argv[1]);
	if (container->philo_num > 255)
		return (ft_error("More 255 philosofers\n"));
	container->timetodie = ft_atoi(argv[2]);
	if (container->timetodie < 60)
		return (ft_error("Lower than 60 2nd arg\n"));
	container->timetoeat = ft_atoi(argv[3]);
	if (container->timetoeat < 60)
		return (ft_error("Lower than 60 3rd arg\n"));
	container->timetosleap = ft_atoi(argv[4]);
	if (container->timetosleap < 60)
		return (ft_error("Lower than 60 4th arg\n"));
	return (0);
}
