/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 10:47:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/23 12:25:27 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo	*create_philos(t_info *info)
{
	t_philo	*philos;
	int		i;
	int		j;

	philos = (t_philo *)malloc(info->nb_philos * sizeof(t_philo));
	if (!philos)
		return (err_msg("Malloc\n"), NULL);
	i = 0;
	while (i < info->nb_philos)
	{
		if (i == info->nb_philos - 1)
			j = 0;
		else
			j = i + 1;
		philos[i].id = i + 1;
		philos[i].nb_times_ate = 0;
		philos[i].time_to_die = 0;
		philos[i].fl = i;
		philos[i].fr = j;
		philos[i].info = info;
		i++;
	}
	return (philos);
}

void	*one_philo(void *param)
{
	t_philo	*philos;

	philos = (t_philo *)param;
	if (p_print(philos[0].info, &philos[0], FORK, GREEN) == -1)
		return (NULL);
	do_task(philos[0].info->time_to_die);
	if (p_print(philos[0].info, &philos[0], DEAD, RED) == -1)
		return (NULL);
	return (NULL);
}
