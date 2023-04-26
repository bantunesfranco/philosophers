/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 12:06:07 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, t_philo *philo)
{
	if (pthread_mutex_lock(&info->forks[philo->fork.left]))
		return (false);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	if (pthread_mutex_lock(&info->forks[philo->fork.right]))
		return (false);
	if (p_print(info, philo, FORK, GREEN) == -1)
		return (false);
	if (p_print(info, philo, EAT, GREEN) == -1)
		return (false);
	philo->time_to_die = get_time();
	do_task(info->time_to_eat);
	philo->nb_times_ate++;
	if (pthread_mutex_unlock(&info->forks[philo->fork.left]))
		return (false);
	if (pthread_mutex_unlock(&info->forks[philo->fork.right]))
		return (false);
	return (true);
}

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, SLEEP, GREEN) == -1)
		return (false);
	philo->time_to_die = get_time();
	do_task(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, GREEN) == -1)
		return (false);
	return (true);
}

bool	has_died(t_info *info, t_philo *philo)
{
	const int	dt = delta_time(philo->time_to_die);

	if (info->time_to_die - dt <= 0)
	{
		info->dead = true;
		p_print(info, philo, DEAD, RED);
		return (true);
	}
	return (false);
}
