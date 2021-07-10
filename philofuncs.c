#include "philo_one.h"

void	locked_print_die(int i)
{
	t_philos	*container;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	printf("%lld %d died", ft_getTime() , (i + 1));
}

int	check_death()
{
	t_philos	*container;
	int			i;
	//int			j;

	container = statlist();
	while (1)
	{
		//j = 0;
		i = 0;
		while (i < container->philo_num)
		{
			//if (container->mustEat > -1 && container->all_philos[i].ate >= container->mustEat)
			//{
			//	pthread_mutex_lock(&container->writeMutex);
			//	j++;
			//	pthread_mutex_unlock(&container->writeMutex);
			//}
			if (ft_getTime() - container->all_philos[i].lastEat
				>= (uint64_t)container->timetodie)
			{
				locked_print_die(i);
				return (1);
			}
			//if (j == container->philo_num)
			//	return (1);
			i++;
		}
	}
	return (0);
}

void	takefork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	pthread_mutex_lock(&container->forks[id]);
	locked_print("has taken the first fork\n", id);
	tmp = (id + 1) % container->philo_num;
	pthread_mutex_lock(&container->forks[tmp]);
	locked_print("has taken the second fork\n", id);
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
	ft_sleepu(time);
}
