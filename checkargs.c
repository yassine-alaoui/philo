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
	if (container->philo_num > 200 || container->philo_num < 1)
		return (ft_error("More 200 philosofers or None\n"));
	container->timetodie = ft_atoi(argv[2]);
	if (container->timetodie < 60)
		return (ft_error("Lower than 60 2nd arg\n"));
	container->timetoeat = ft_atoi(argv[3]);
	if (container->timetoeat < 60)
		return (ft_error("Lower than 60 3rd arg\n"));
	container->timetosleap = ft_atoi(argv[4]);
	if (container->timetosleap < 60)
		return (ft_error("Lower than 60 4th arg\n"));
	if (argv[5])
	{
		container->mustEat = ft_atoi(argv[5]);
		if (container->mustEat <= 0)
			return (ft_error("Negative or Null 5th arg\n"));
	}
	else if (!argv[5])
		container->mustEat = -1;
	return (0);
}
