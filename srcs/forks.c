/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:52:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/23 12:09:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_forks(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->msg, NULL))
		return (err_msg("Create mutex"));
	if (pthread_mutex_init(&info->death, NULL))
		return (err_msg("Create mutex"));
	if (pthread_mutex_init(&info->done, NULL))
		return (err_msg("Create mutex"));
	info->forks = malloc(info->nb_philos * sizeof(pthread_mutex_t));
	if (!info->forks)
		return (err_msg("Malloc\n"));
	while (i < info->nb_philos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (clean_forks(info, i), err_msg("Create mutex"));
		i++;
	}
	return (0);
}

void	clean_forks(t_info *info, int n)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->msg);
	pthread_mutex_destroy(&info->death);
	pthread_mutex_destroy(&info->done);
	while (i < n)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
}

void	unlock_forks(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(&info->msg);
	pthread_mutex_unlock(&info->death);
	while (i < info->nb_philos)
	{
		pthread_mutex_unlock(&info->forks[i]);
		i++;
	}
}
