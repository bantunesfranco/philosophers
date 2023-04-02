/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 13:34:45 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/19 13:34:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

typedef struct s_fork
{
	int	left;
	int	right;
}	t_fork;

typedef struct s_philo
{
	int			id;
	int			nb_times_ate;
	long long	time_to_die;
	t_fork		fork;
	pthread_t	thread;
}	t_philo;

typedef struct s_info
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
	int				t0;
	bool			dead;
	t_philo			*philos;
	pthread_t		*bossman;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*msg;
}	t_info;

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define END "\033[0m"

# define ARG0 "Incorrect number of arguments.\n\
Use: ./philo nb_of_philos time_to_die time_to_eat \
time_to_sleep [nb_of_times_must_eat]\n\
The last parameter is optional\n"
# define ARG1 "nb_of_philos is invalid\n"
# define ARG2 "time_to_die is invalid\n"
# define ARG3 "time_to_eat is invalid\n"
# define ARG4 "time_to_sleep is invalid\n"
# define ARG5 "nb_of_times_must_eat is invalid\n"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

/* utils */
int		err_msg(char *msg);
int		p_atoi(char *str);
int		p_strlen(char *str);
int		p_print(t_info *info, t_philo *philo, char *str, char *color);

/* init */
int		create_philos(t_info *info);
int		create_threads(t_info *info);
int		create_forks(t_info *info);

/* time */
long	get_time(void);
long	delta_time(long time);
void	do_task(long time);

/* action */
bool	p_eat(t_info *info, t_philo *philo);
bool	p_sleep(t_info *info, t_philo *philo);
bool	p_think(t_info *info, t_philo *philo);
bool	has_died(t_info *info, t_philo *philo);

/* exit */
void	kill_philos(t_info *info);
void	clean_forks(t_info *info, int n);
void	free_info(t_info *info);

#endif