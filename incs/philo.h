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
	t_fork		*fork;
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
	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	msg;
}	t_info;

# define ARG0 "Error: Incorrect number of arguments.\n\
Use: ./philo nb_of_philos time_to_die time_to_eat \
time_to_sleep [nb_of_times_must_eat]\n\
The last parameter is optional\n"
# define ARG1 "Error: nb_of_philos is invalid\n"
# define ARG2 "Error: time_to_die is invalid\n"
# define ARG3 "Error: time_to_eat is invalid\n"
# define ARG4 "Error: time_to_sleep is invalid\n"
# define ARG5 "Error: nb_of_times_must_eat is invalid\n"

# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEAD "died"

int		err_msg(char *msg);
int		p_atoi(char *str);
int		p_strlen(char *str);
int		create_philos(t_info *info);

#endif