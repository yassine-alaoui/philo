#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos	t_philos;
typedef struct s_philo	t_philo;

// status = 0 eat 1 sleep 2 think 3 dies
struct s_philos
{
	int				philo_num;
	int				timetodie;
	int				timetoeat;
	int				timetosleap;
	int				status;
	t_philo			*all_philos;
	t_philo			checkdeath;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writeMutex;
	//fork and die mutex
};

struct s_philo
{
	pthread_t		thread_id;
	pthread_t		death_id;
	pthread_mutex_t	death_lock;
	//int				id;
	//t_philos		*global;
};

//	philo funcs
void		startPhilo(void);
void		ft_creations(void);
void		*begin(void *arg);
void		takefork(int id);
void		dropfork(int id);
void		eat(int id, int time);
void		ft_sleep(int time);

// generall functs
int			ft_strlen(char *str);
void		ft_sleepu(unsigned long long time);
t_philos	*statlist(void);
int			isAllNumber(char *str);
int			ft_atoi(char *str);
int			ft_error(char *str);
void		ft_putnbr_fd(int n, int fd);
void		ft_putchar_fd(int c, int fd);

// other functs
int			checkArgs(char **argv);
int			checkNumbers(char **argv);

#endif