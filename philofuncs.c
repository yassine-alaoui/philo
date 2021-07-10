#include "philo_one.h"

int	locked_print_die(int i)
{
	t_philos	*container;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	printf("%lld %d died", ft_getTime(), (i + 1));
	return (1);
}

int	check_death(void)
{
	t_philos	*container;
	int			i;
	int			j;

	container = statlist();
	while (1)
	{
		j = 0;
		i = -1;
		while (++i < container->philo_num)
		{
			if (container->all_philos[i].iseating)
				continue ;
			pthread_mutex_lock(&container->all_philos[i].eating);
			if (ft_getTime() - container->all_philos[i].lastEat
				>= (uint64_t)container->timetodie)
				return (locked_print_die(i));
			if (container->done == container->philo_num)
				return (1);
			pthread_mutex_unlock(&container->all_philos[i].eating);
		}
		usleep(100);
	}
	return (0);
}

void	takefork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	pthread_mutex_lock(&container->forks[id]);
	locked_print("has taken a fork\n", id);
	tmp = (id + 1) % container->philo_num;
	pthread_mutex_lock(&container->forks[tmp]);
	locked_print("has taken a fork\n", id);
}

void	dropfork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	locked_print("is sleeping\n", id);
	pthread_mutex_unlock(&container->forks[id]);
	tmp = (id + 1) % container->philo_num;
	pthread_mutex_unlock(&container->forks[tmp]);
}

void	eat(int id, int time)
{
	t_philos	*container;

	container = statlist();
	container->all_philos[id].lastEat = ft_getTime();
	locked_print("is eating\n", id);
	pthread_mutex_lock(&container->all_philos[id].eating);
	container->all_philos[id].iseating = 1;
	ft_sleepu(time);
	pthread_mutex_unlock(&container->all_philos[id].eating);
	container->all_philos[id].iseating = 0;
}
