#include "philo_one.h"

void	locked_print_die(int i)
{
	t_philos	*container;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	printf("%d died", (i + 1));
}

int	check_death()
{
	t_philos	*container;
	int			i;

	i = 0;
	container = statlist();
	while (1)
	{
		i = 0;
		while (i < container->philo_num)
		{
			if (ft_getTime() - container->all_philos[i].lastEat
				>= (uint64_t)container->timetodie)
			{
				locked_print_die(i);
				return (1);
			}
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
	if (id % 2 != 0)
		usleep(100);
	pthread_mutex_lock(&container->forks[id]);
	locked_print("has taken the first fork\n", id);
	tmp = (id - 1) % container->philo_num;
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
	tmp = (id - 1) % container->philo_num;
	pthread_mutex_unlock(&container->forks[tmp]);
}

void	eat(int id, int time)
{
	t_philos	*container;

	container = statlist();
	locked_print("is eating\n", id);
	ft_sleepu(time);
}

//void	ft_sleep(int time)
//{
//	ft_sleepu(time);
//}
