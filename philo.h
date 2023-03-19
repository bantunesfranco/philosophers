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

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <errno.h>

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

typedef struct	s_info
{
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_to_eat;
	int				t0;
	t_philo			*philos;
	pthread_mutex_t	fork;

}	t_info;

#define FORK "has taken a fork"
#define EAT "is eating"
#define SLEEP "is sleeping"
#define THINK "is thinking"
#define DEAD "died"

#endif