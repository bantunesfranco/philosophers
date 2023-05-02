/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/02 10:15:38 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	working(t_info *info, t_philo *philo)
{
	if (p_eat(info, philo) == false)
		return (-1);
	if (philos->nb_times_ate != info->nb_times_to_eat)
	{
		if (p_think(info, philo) == false)
			return (-1);
		if (p_sleep(info, philo) == false)
			return (-1);
	}
	return (0);
}

void	*work(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	if (philo->info->nb_times_to_eat > 0)
	{
		while (philo->nb_times_ate < philo->info->nb_times_to_eat \
		&& philo->info->dead == false)
		{
			if (working(philo->info, philo) == -1)
				break ;
		}
	}
	else
	{
		while (philo->info->dead == false)
		{
			if (working(philo->info, philo) == -1)
				break ;
		}
	}
	return (NULL);
}

void	*payday(void *param)
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = (t_philo *)param;
	if (philos[i]->info->nb_times_to_eat > 0)
	{
		while (philos[i].nb_times_ate < philos[i].info->nb_times_to_eat \
		&& philos[i].info->dead == false)
		{
			if (has_died(philos, &i) == true)
				break ;
		}
	}
	else
	{
		while (philos[i].info->dead == false)
		{
			if (has_died(philos, &i) == true)
				break ;
		}
	}
	return (NULL);
}
