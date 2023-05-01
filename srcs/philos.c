/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 10:47:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/01 18:12:06 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_philos(t_info *info, t_philo *philos)
{
	int	i;
	int	j;

	philos = (t_philo *)malloc(info->nb_philos * sizeof(t_philo));
	if (!philos)
		return (err_msg("Malloc\n"));
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
		philos[i].fork.left = i;
		philos[i].fork.right = j;
		philos[i].info = info;
		i++;
	}
	return (0);
}

int	one_philo(t_info *info)
{
	info->t0 = get_time();
	if (p_print(info, &info->philos[0], FORK, GREEN) == -1)
		return (-1);
	do_task(info->time_to_die);
	if (p_print(info, &info->philos[0], DEAD, RED) == -1)
		return (-1);
	return (0);
}
