/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:52:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/27 18:52:05 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = (pthread_mutex_t *)malloc(info->nb_philos * sizeof(pthread_mutex_t));
	if (!info->forks)
		return (err_msg("Error: Malloc\n"));
	while (i < info->nb_philos)
	{
		if (pthread_mutex_init(&info.forks[i], NULL))
		{
			while (i >= 0)
			{
				pthread_mutex_destroy(&info.forks[i], NULL);
				i--;
			}
			return (err_msg("Error: Create mutex"));
		}
		i++;
	}
	return (0);
}

void	destroy_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nb_philos)
	{
		pthread_mutex_destroy(&info.forks[i], NULL);
		i++;
	}
}
