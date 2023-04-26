/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:50:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 11:51:30 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	info->t0 = get_time();
	while (i < info->nb_philos)
	{
		if (pthread_create(&info->philos[i].thread, NULL, &work, info))
			return (err_msg("Create thread\n"));
		usleep(1000);
		i++;
	}
	if (pthread_create(&info->bossman, NULL, &payday, info))
		return (err_msg("Create thread\n"));
	usleep(1000);
	return (join_threads(info));
}

int	join_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_join(info->philos[i].thread, NULL))
			return (err_msg("Join thread\n"));
		i++;
	}
	if (pthread_join(info->bossman, NULL))
		return (err_msg("Join thread\n"));
	return (0);
}
