/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/17 09:25:42 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (is_end(info) == true)
		return (false);
	if (p_print(info, philo, SLEEP, CYAN) == -1)
		return (false);
	ft_usleep(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (is_end(info) == true)
		return (false);
	if (p_print(info, philo, THINK, CYAN) == -1)
		return (false);
	return (true);
}

bool	is_dead(t_philo *philo, t_info *info)
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

void	done_eating(t_info *info)
{
	pthread_mutex_lock(&info->msg);
	printf("%s%lld	Everyone is done eating\n%s", \
	MAGENTA, delta_time(info->t0), END);
	pthread_mutex_lock(&info->death);
	info->dead = true;
	pthread_mutex_unlock(&info->death);
	pthread_mutex_unlock(&info->msg);
}

bool	is_end(t_info *info)
{
	pthread_mutex_lock(&info->death);
	if (info->dead == true)
	{
		pthread_mutex_unlock(&info->death);
		return (true);
	}
	pthread_mutex_unlock(&info->death);
	return (false);
}
