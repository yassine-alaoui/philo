#include "philo_one.h"

void	takefork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	pthread_mutex_lock(&container->forks[id]);
	pthread_mutex_lock(&container->writeMutex);
	ft_putnbr_fd(id, 1);
	write(1, " has taken the first fork\n", 26);
	tmp = (id - 1) % container->philo_num;
	pthread_mutex_unlock(&container->writeMutex);
	pthread_mutex_lock(&container->forks[tmp]);
	pthread_mutex_lock(&container->writeMutex);
	ft_putnbr_fd(id, 1);
	write(1, " has taken the second fork\n", 27);
	pthread_mutex_unlock(&container->writeMutex);
}

void	dropfork(int id)
{
	t_philos	*container;
	int			tmp;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	ft_putnbr_fd(id, 1);
	write(1, " is sleeping\n", 13);
	pthread_mutex_unlock(&container->forks[id]);
	tmp = (id - 1) % container->philo_num;
	pthread_mutex_unlock(&container->forks[tmp]);
	pthread_mutex_unlock(&container->writeMutex);
}

void	eat(int id, int time)
{
	t_philos	*container;

	container = statlist();
	pthread_mutex_lock(&container->writeMutex);
	ft_putnbr_fd(id, 1);
	write(1, " is eating\n", 11);
	pthread_mutex_unlock(&container->writeMutex);
	usleep(time * 1000);
}

void	ft_sleep(int time)
{
	usleep(time * 1000);
}
