/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/24 11:54:49 by codespace     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->eat);
	pthread_mutex_lock(&info->forks[philo->fl]);
	pthread_mutex_lock(&info->forks[philo->fr]);
	if (p_print(info, philo, FORK, GREEN) == -1 \
	|| p_print(info, philo, FORK, GREEN) == -1 \
	|| p_print(info, philo, EAT, BLUE) == -1)
		return (pthread_mutex_unlock(&info->forks[philo->fl]), \
		pthread_mutex_unlock(&info->forks[philo->fr]), \
		pthread_mutex_unlock(&philo->eat), false);
	philo->time_to_die = get_time();
	philo->nb_times_ate++;
	do_task(info->time_to_eat);
	pthread_mutex_unlock(&info->forks[philo->fl]);
	pthread_mutex_unlock(&info->forks[philo->fr]);
	pthread_mutex_unlock(&philo->eat);
	return (true);
}

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, SLEEP, CYAN) == -1)
		return (false);
	pthread_mutex_lock(&info->death);
	do_task(info->time_to_sleep);
	pthread_mutex_unlock(&info->death);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, CYAN) == -1)
		return (false);
	return (true);
}

bool	is_end(t_philo *philos, t_info *info, int *i)
{
	int	dt;

	if (*i == info->nb_philos - 1)
		*i = 0;
	pthread_mutex_lock(&philos[*i].eat);
	pthread_mutex_lock(&info->done);
	if (info->philo_done == info->nb_philos)
		return (pthread_mutex_unlock(&philos[*i].eat),\
		pthread_mutex_unlock(&info->done), true);
	pthread_mutex_unlock(&info->done);
	dt = delta_time(philos[*i].time_to_die);
	if (dt > info->time_to_die)
	{
		if (p_print(info, &philos[*i], DEAD, RED) == -1)
			return (false);
		pthread_mutex_lock(&info->death);
		info->dead = true;
		pthread_mutex_unlock(&info->death);
		pthread_mutex_unlock(&philos[*i].eat);
		return (true);
	}
	pthread_mutex_unlock(&philos[*i].eat);
	i++;
	return (false);
}
