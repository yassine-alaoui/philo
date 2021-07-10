#include "philo_one.h"

void	ft_sleepu(unsigned long long time)
{
	unsigned long long	start;
	unsigned long long	end;

	start = ft_getTime();
	end = start + time;
	while (ft_getTime() < end)
	{
		usleep(100);
	}
}

void	*begin(void *arg)
{
	int			i;
	t_philos	*container;

	container = statlist();
	i = *(int *)arg;
	container->all_philos[i].ate = 0;
	container->all_philos[i].iseating = 0;
	if (i % 2)
		usleep(100);
	while (1)
	{
		if (container->mustEat > 0 && container->all_philos[i].ate
			== container->mustEat)
			container->done++;
		takefork(i);
		container->all_philos[i].ate++;
		eat(i, container->timetoeat);
		dropfork(i);
		ft_sleepu(container->timetosleap);
		locked_print("is thinking\n", i);
	}
	return (0);
}

int	ft_creations(void)
{
	t_philos	*container;
	int			i;
	int			*a;

	container = statlist();
	i = 0;
	pthread_mutex_init(&container->writeMutex, NULL);
	while (i < container->philo_num)
		pthread_mutex_init(&container->forks[i], NULL),
		pthread_mutex_init(&container->all_philos[i++].eating, NULL);
	i = 0;
	while (i < container->philo_num)
	{
		a = malloc(sizeof(int));
		*a = i;
		container->all_philos[i].lastEat = ft_getTime();
		if (pthread_create(&container->all_philos[i].thread_id,
				NULL, &begin, a) != 0)
		{
			free(container->all_philos);
			return (ft_error("Failed to create a thread\n"));
		}
		i++;
	}
	return (0);
}

int	endPhilo(void)
{
	int			i;
	t_philos	*container;

	i = 0;
	container = statlist();
	while (i < container->philo_num)
	{
		if (pthread_join(container->all_philos[i++].thread_id, NULL) != 0)
		{
			free(container->all_philos);
			return (ft_error("Failed to join a thread\n"));
		}
	}
	return (0);
}

int	startPhilo(void)
{
	t_philos	*container;
	int			i;

	i = 0;
	container = statlist();
	container->all_philos = malloc(sizeof(t_philo) * container->philo_num);
	container->forks = malloc(sizeof(pthread_mutex_t) * container->philo_num);
	container->done = 0;
	if (ft_creations())
		return (1);
	return (0);
}
