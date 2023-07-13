/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/13 17:05:45 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	end_sim(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->eat);
	if (info->nb_meals > 0 && philo->nb_times_ate == info->nb_meals)
	{
		info->philo_done++;
		pthread_mutex_unlock(&philo->eat);
		p_print(philo->info, philo, "is done eating", MAGENTA);
		return (true);
	}
	pthread_mutex_unlock(&philo->eat);
	return (false);
}

void	*work(void *param)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)param;
	info = philo->info;
	while (1)
	{
		if (p_eat(info, philo) == false)
			return (NULL);
		if (end_sim(philo, info) == true)
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
	while (info->philo_done == info->nb_philos)
	{
		if (delta_time(time) >= info->time_to_die)
		{
			i = 0;
			while (i < info->nb_philos && info->philo_done == info->nb_philos)
			{
				if (is_end(&philos[i], info) == true)
					return (NULL);
				i++;
			}
			time = get_time();
		}
	}
	return (NULL);
}
