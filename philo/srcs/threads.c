/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:50:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/07 09:14:32 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_threads(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	info->t0 = get_time();
	if (info->t0 == -1)
		return (-1);
	while (i < info->nb_philos)
	{
		philos[i].last_eat = info->t0;
		if (pthread_create(&philos[i].thread, NULL, &work, &philos[i]))
			return (err_msg("Create thread\n"));
		i++;
	}
	return (join_threads(info, philos));
}

int	join_threads(t_info *info, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (err_msg("Join thread\n"));
		i++;
	}
	return (0);
}
