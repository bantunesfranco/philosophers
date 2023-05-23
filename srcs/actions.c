/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/23 12:09:59 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->eat);
	pthread_mutex_lock(&info->forks[philo->fl]);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	pthread_mutex_lock(&info->forks[philo->fr]);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	if (p_print(info, philo, EAT, GREEN) == -1)
		return (false);
	do_task(info->time_to_eat);
	philo->time_to_die = get_time();
	philo->nb_times_ate++;
	pthread_mutex_unlock(&info->forks[philo->fl]);
	pthread_mutex_unlock(&info->forks[philo->fr]);
	pthread_mutex_unlock(&info->eat);
	return (true);
}

bool	p_sleep(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->death);
	if (p_print(info, philo, SLEEP, GREEN) == -1)
		return (pthread_mutex_lock(&info->death), false);
	do_task(info->time_to_sleep);
	pthread_mutex_lock(&info->death);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, GREEN) == -1)
		return (false);
	return (true);
}

bool	is_end(t_philo *philos, t_info *info, int *i)
{
	int	dt;

	dt = delta_time(info->time_to_die);
	if (*i == info->nb_philos - 1)
		*i = 0;
	if (dt > info->time_to_die)
	{
		pthread_mutex_lock(&info->eat);
		if (info->philo_done == info->nb_philos)
			return (true);
		if (p_print(info, &philos[*i], DEAD, RED) == -1)
			return (pthread_mutex_unlock(&info->eat), false);
		pthread_mutex_lock(&info->death);
		info->dead = true;
		pthread_mutex_unlock(&info->death);
		pthread_mutex_unlock(&info->eat);
		return (true);
	}
	i++;
	return (false);
}
