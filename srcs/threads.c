/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:50:11 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/27 18:50:11 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		if (pthread_create(&info->philo[i].thread, NULL, &routine, info))
			return (err_msg("Create thread\n"));
	}
	if (pthread_create(&info->bossman, NULL, &payday, info))
		return (err_msg("Create thread\n"));
	return (0);
}
