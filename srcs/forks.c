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
	if (pthread_mutex_init(&info->msg, NULL))
		return (err_msg("Error: Create mutex"));
	info->forks = (pthread_mutex_t *)malloc(info->nb_philos * sizeof(pthread_mutex_t));
	if (!info->forks)
		return (err_msg("Error: Malloc\n"));
	while (i < info->nb_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (clean_forks(info, i), err_msg("Error: Create mutex"));
		i++;
	}
	return (0);
}

void	clean_forks(t_info *info, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(info->msg);
	while (i < n)
	{
		pthread_mutex_destroy(info->forks[i]);
		i++;
	}
}
