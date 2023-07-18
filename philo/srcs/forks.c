/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   forks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/27 18:52:05 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/18 20:37:57 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_forks(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	info->forks = malloc(info->nb_philos * sizeof(pthread_mutex_t));
	if (!info->forks)
		return (err_msg("Malloc\n"));
	while (++i < info->nb_philos)
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (clean_forks(philos, info, i, 5), err_msg("Create mutex\n"));
	i = -1;
	while (++i < info->nb_philos)
		if (pthread_mutex_init(&philos[i].eat, NULL))
			return (clean_forks(philos, info, i, 4), err_msg("Create mutex\n"));
	if (pthread_mutex_init(&info->msg, NULL))
		return (clean_forks(philos, info, i, 3), err_msg("Create mutex\n"));
	if (pthread_mutex_init(&info->death, NULL))
		return (clean_forks(philos, info, i, 2), err_msg("Create mutex\n"));
	if (pthread_mutex_init(&info->done, NULL))
		return (clean_forks(philos, info, i, 1), err_msg("Create mutex\n"));
	return (0);
}

static void	clean_forks2(t_philo *philos, t_info *info, int mode)
{
	int	i;

	i = -1;
	if (mode <= 3)
	{
		while (++i < info->nb_philos)
		{
			pthread_mutex_destroy(&info->forks[i]);
			pthread_mutex_destroy(&philos[i].eat);
		}
	}
	if (mode <= 2)
		pthread_mutex_destroy(&info->msg);
	if (mode <= 1)
		pthread_mutex_destroy(&info->death);
	if (mode == 0)
		pthread_mutex_destroy(&info->done);
}

void	clean_forks(t_philo *philos, t_info *info, int n, int mode)
{
	int	i;

	i = -1;
	if (mode == 5)
		while (++i < n)
			pthread_mutex_destroy(&info->forks[i]);
	i = -1;
	if (mode == 4)
	{
		while (++i < info->nb_philos)
		{
			pthread_mutex_destroy(&info->forks[i]);
			if (i < n)
				pthread_mutex_destroy(&philos[i].eat);
		}
	}
	clean_forks2(philos, info, mode);
}
