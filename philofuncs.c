#include "philo_one.h"

void	check_death()
{
	t_philos	*container;
	int			i;

	i = 0;
	container = statlist();
	while (i < container->philo_num)
	{
		
	}
}

void	takefork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	if (id % 2 != 0)
		usleep(100);
	//container->status = check_death();
	pthread_mutex_lock(&container->forks[id]);
	//pthread_mutex_lock(&container->writeMutex);
	//ft_putnbr_fd(id, 1);
	//write(1, " has taken the first fork\n", 26);
	printf("%d has taken the first fork\n", id);
	tmp = (id - 1) % container->philo_num;
	//pthread_mutex_unlock(&container->writeMutex);
	pthread_mutex_lock(&container->forks[tmp]);
	//pthread_mutex_lock(&container->writeMutex);
	//ft_putnbr_fd(id, 1);
	//write(1, " has taken the second fork\n", 27);
	printf("%d has taken the second fork\n", id);
	//pthread_mutex_unlock(&container->writeMutex);
}

void	dropfork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	//pthread_mutex_lock(&container->writeMutex);
	//ft_putnbr_fd(id, 1);
	//write(1, " is sleeping\n", 13);
	printf("%d is sleeping\n", id);
	pthread_mutex_unlock(&container->forks[id]);
	tmp = (id - 1) % container->philo_num;
	pthread_mutex_unlock(&container->forks[tmp]);
	//pthread_mutex_unlock(&container->writeMutex);
}

void	eat(int id, int time)
{
	t_philos	*container;

	container = statlist();
	//pthread_mutex_lock(&container->writeMutex);
	//ft_putnbr_fd(id, 1);
	//write(1, " is eating\n", 11);
	printf("%d is eating\n", id);
	//pthread_mutex_unlock(&container->writeMutex);
	ft_sleepu(time);
}

void	ft_sleep(int time)
{
	ft_sleepu(time);
}
