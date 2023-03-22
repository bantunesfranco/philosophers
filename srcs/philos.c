/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 10:47:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/22 17:00:31 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*routine(void *param)
{
	t_info	*info;

	info = param;
	// printf("%d\n", info->philos[0].id);
	printf("HI\n");
	return (NULL);
}

int	create_philos(t_info *info)
{
	int			i;
	t_philo		philo;
	// int			j;

	i = -1;
	while (++i < info->nb_philos)
	{
		// j = i + 1;
		philo.id = i + 1;
		philo.nb_times_ate = 0;
		philo.time_to_die = info->time_to_die;
		// philo.fork->left = j;
		// philo.fork->right = i;
		if (pthread_create(&philo.thread, NULL, &routine, NULL))
			return (err_msg("Error: Create thread\n"));
		info->philos[i] = philo;
	}
	return (0);
}
