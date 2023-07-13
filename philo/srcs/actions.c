/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/13 17:22:51 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, SLEEP, CYAN) == -1)
		return (false);
	ft_usleep(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, CYAN) == -1)
		return (false);
	return (true);
}

bool	is_dead(t_philo *philo, t_info *info)
{
	int			dt;

	dt = delta_time(philo->last_eat);
	if (dt >= info->time_to_die)
	{
		p_print(info, philo, DEAD, RED);
		pthread_mutex_lock(&info->death);
		info->dead = true;
		pthread_mutex_unlock(&info->death);
		return (true);
	}
	return (false);
}

bool	is_end(t_philo *philo, t_info *info)
{
	int			dt;

	pthread_mutex_lock(&philo->eat);
	dt = delta_time(philo->last_eat);
	if (dt >= info->time_to_die)
	{
		p_print(info, philo, DEAD, RED);
		pthread_mutex_lock(&info->death);
		info->dead = true;
		pthread_mutex_unlock(&info->death);
		pthread_mutex_unlock(&philo->eat);
		return (true);
	}
	pthread_mutex_unlock(&philo->eat);
	return (false);
}
