/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/17 09:31:42 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*work(void *param)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)param;
	info = philo->info;
	while (is_end(info) == false)
	{
		if (p_eat(info, philo) == false)
			return (NULL);
		if (p_sleep(info, philo) == false)
			return (NULL);
		if (p_think(info, philo) == false)
			return (NULL);
	}
	return (NULL);
}

void	*payday(void *param)
{
	t_philo	*philos;
	t_info	*info;
	int		i;
	long	time;

	philos = (t_philo *)param;
	info = philos[0].info;
	time = get_time();
	while (1)
	{
		pthread_mutex_lock(&info->done);
		if (info->philo_done == info->nb_philos)
			return (pthread_mutex_unlock(&info->done), done_eating(info), NULL);
		pthread_mutex_unlock(&info->done);
		if (delta_time(time) >= info->time_to_die)
		{
			i = -1;
			while (++i < info->nb_philos)
				if (is_dead(&philos[i], info))
					return (NULL);
			time = get_time();
		}
	}
	return (NULL);
}
