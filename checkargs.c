#include "philo_one.h"

void	checkArgs(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!isAllNumber(argv[i]))
		{
			write(2, "Not a valid argument\n", 21);
			exit (1);
		}
		i++;
	}
}

void	checkNumbers(char **argv)
{
	t_philos	*container;

	container = statlist();
	container->philo_num = ft_atoi(argv[1]);
	if (container->philo_num > 255)
		ft_error("More 255 philosofers\n");
	container->timetodie = ft_atoi(argv[2]);
	if (container->timetodie < 60)
		ft_error("Lower than 60 2nd arg\n");
	container->timetoeat = ft_atoi(argv[3]);
	if (container->timetoeat < 60)
		ft_error("Lower than 60 3rd arg\n");
	container->timetosleap = ft_atoi(argv[4]);
	if (container->timetosleap < 60)
		ft_error("Lower than 60 4th arg\n");
}
