/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:50:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/23 11:20:36 by bfranco       ########   odam.nl         */
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
		if (pthread_create(&philos[i].thread, NULL, &work, &philos[i]))
			return (err_msg("Create thread\n"));
		i++;
	}
	if (pthread_create(&info->bossman, NULL, &payday, philos))
		return (err_msg("Create thread\n"));
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
	if (pthread_join(info->bossman, NULL))
		return (err_msg("Join thread\n"));
	return (0);
}
