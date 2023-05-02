/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/02 10:19:42 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, t_philo *philo)
{
	if (pthread_mutex_lock(&info->forks[philo->fl]))
		return (false);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	if (pthread_mutex_lock(&info->forks[philo->fr]))
		return (false);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	if (p_print(info, philo, EAT, GREEN) == -1)
		return (false);
	do_task(info->time_to_eat);
	philo->time_to_die = get_time();
	philo->nb_times_ate++;
	if (pthread_mutex_unlock(&info->forks[philo->fl]))
		return (false);
	if (pthread_mutex_unlock(&info->forks[philo->fr]))
		return (false);
	return (true);
}

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, SLEEP, GREEN) == -1)
		return (false);
	do_task(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, GREEN) == -1)
		return (false);
	return (true);
}

bool	has_died(t_philo *philos, int *i)
{
	int	dt;

	dt = delta_time(philos[*i].time_to_die);
	if (*i == philos[*i].info->nb_philos)
		*i = 0;
	if (dt > philos[*i].info->time_to_die)
	{
		if (p_print(philos[*i].info, &philos[*i], DEAD, RED) == -1)
			return (false);
		philos[*i].info->dead = true;
		return (true);
	}
	i++;
	return (false);
}
