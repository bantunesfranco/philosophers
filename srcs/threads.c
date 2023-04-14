/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:50:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/14 13:20:53 by bruno         ########   odam.nl         */
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
		if (pthread_create(&info->philos[i].thread, NULL, work, info))
			return (err_msg("Create thread\n"));
		i++;
	}
	if (pthread_create(&info->bossman, NULL, payday, info))
		return (err_msg("Create thread\n"));
	join_philos(info);
	return (0);
}
