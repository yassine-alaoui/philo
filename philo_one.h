#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philos	t_philos;
typedef struct s_philo	t_philo;

struct s_philos
{
	int				philo_num;
	int				timetodie;
	int				timetoeat;
	int				timetosleap;
	int				mustEat;
	int				done;
	t_philo			*all_philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writeMutex;
};

struct s_philo
{
	pthread_t			thread_id;
	pthread_mutex_t		eating;
	int					ate;
	int					iseating;
	unsigned long long	lastEat;
};

//	philo funcs
int					startPhilo(void);
int					endPhilo(void);
int					ft_creations(void);
void				*begin(void *arg);
void				takefork(int id);
void				dropfork(int id);
void				eat(int id, int time);
int					check_death(void);

// generall functs
int					ft_strlen(char *str);
void				ft_sleepu(unsigned long long time);
t_philos			*statlist(void);
int					isAllNumber(char *str);
int					ft_atoi(char *str);
int					ft_error(char *str);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(int c, int fd);
unsigned long long	ft_getTime(void);
void				locked_print(char	*str, int	id);

// other functs
int					checkArgs(char **argv);
int					checkNumbers(char **argv);

#endif