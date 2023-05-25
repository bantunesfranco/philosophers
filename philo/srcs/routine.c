/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/25 17:51:13 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	working(t_info *info, t_philo *philo)
{
	if (p_eat(info, philo) == false)
		return (-1);
	if (is_dead(philo, info) == true)
		return (-1);
	if (philo->nb_times_ate == info->nb_times_to_eat)
		// return (p_print(info, philo, "is done eating", MAGENTA), -1);
		return (-1);
	if (p_sleep(info, philo) == false)
		return (-1);
	if (is_dead(philo, info) == true)
		return (-1);
	if (p_think(info, philo) == false)
		return (-1);
	return (0);
}

void	*work(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		if (working(philo->info, philo) == -1)
			break ;
	}
	return (NULL);
}

// void	*payday(void *param)
// {
// 	t_philo	*philos;
// 	int		i;

// 	i = 0;
// 	philos = (t_philo *)param;
// 	while (1)
// 	{
// 		if (is_end(philos, philos[i].info, &i) == true)
// 			break ;
// 	}
// 	return (NULL);
// }
