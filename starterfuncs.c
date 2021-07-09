#include "philo_one.h"

void	ft_sleepu(unsigned long long time)
{
	struct timeval		tv;
	unsigned long long	start;
	unsigned long long	end;

	gettimeofday(&tv, NULL);
	start = (tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000);
	end = start + time;
	while (((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000)) < end)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
	}
}

void	*begin(void *arg)
{
	int			i;
	t_philos	*container;

	container = statlist();
	i = *(int *)arg;
	while (container->status == 0)
	{
		takefork(i);
		eat(i, container->timetoeat);
		ft_sleep(container->timetosleap);
		dropfork(i);
	}
	return (0);
}

void	ft_creations(void)
{
	t_philos	*container;
	int			i;
	int			*a;

	container = statlist();
	i = 0;
	//pthread_mutex_init(&container->writeMutex, NULL);
	pthread_create(&container->checkdeath, NULL, &check_death, NULL);
	while (i < container->philo_num)
		pthread_mutex_init(&container->forks[i++], NULL);
	i = 0;
	while (i < container->philo_num)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&container->all_philos[i].thread_id,
				NULL, &begin, a) != 0)
			free(container->all_philos), ft_error("Failed to create a thread\n");
		i++;
	}
}

void	startPhilo(void)
{
	t_philos	*container;
	int			i;

	i = 0;
	container = statlist();
	container->status = 0;
	container->all_philos = malloc(sizeof(t_philo) * container->philo_num);
	container->forks = malloc(sizeof(pthread_mutex_t) * container->philo_num);
	ft_creations();
	i = 0;
	while (i < container->philo_num)
		if (pthread_join(container->all_philos[i++].thread_id, NULL) != 0)
			free(container->all_philos), ft_error("Failed to join a thread\n");
}
