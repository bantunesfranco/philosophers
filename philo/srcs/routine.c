/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/10 17:13:35 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*work(void *param)
{
	t_philo	*philo;
	t_info	*info;

	philo = (t_philo *)param;
	info = philo->info;
	while (1)
	{
		if (info->nb_times_to_eat > 0 \
		&& philo->nb_times_ate == info->nb_times_to_eat)
		{
			p_print(philo->info, philo, "is done eating", MAGENTA);
			break ;
		}
		if (p_eat(info, philo) == false)
			break ;
		if (info->nb_times_to_eat > 0 \
		&& philo->nb_times_ate == info->nb_times_to_eat)
		{
			p_print(philo->info, philo, "is done eating", MAGENTA);
			break ;
		}
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
		if (delta_time(time) >= info->time_to_die)
		{
			i = 0;
			while (i < info->nb_philos)
			{
				if (is_dead(&philos[i], info) == true)
					return (kill_threads(philos, info->nb_philos), NULL);
				i++;
			}
			time = get_time();
		}
	}
	return (NULL);
}
