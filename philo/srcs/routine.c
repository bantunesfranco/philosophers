/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/10 20:26:04 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	end_sim(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->eat);
	if (info->nb_meals > 0 && philo->nb_times_ate == info->nb_meals)
	{
		p_print(philo->info, philo, "is done eating", MAGENTA);
		return (true);
	}
	pthread_mutex_unlock(&philo->eat);
	pthread_mutex_lock(&info->death);
	if (info->dead == true)
	{
		pthread_mutex_unlock(&info->death);
		return (true);
	}
	pthread_mutex_unlock(&info->death);
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
		if (end_sim(philo, info) == true)
			break ;
		if (p_eat(info, philo) == false)
			break ;
		if (end_sim(philo, info) == true)
			break ;
		if (p_sleep(info, philo) == false)
			break ;
		if (p_think(info, philo) == false)
			break ;
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
		if (info->philo_done == info->nb_philos)
			return (NULL);
		if (delta_time(time) >= info->time_to_die)
		{
			i = 0;
			while (i < info->nb_philos)
			{
				if (is_dead(&philos[i], info) == true)
					return (NULL);
				i++;
			}
			time = get_time();
		}
	}
	return (NULL);
}
