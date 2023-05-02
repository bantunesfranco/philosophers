/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 10:47:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/02 10:22:06 by bruno         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

t_philo *create_philos(t_info *info, t_philo *philos)
{
	int	i;
	int	j;

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

int	one_philo(t_info *info)
{
	info->t0 = get_time();
	if (p_print(info, philos[0], FORK, GREEN) == -1)
		return (-1);
	do_task(info->time_to_die);
	if (p_print(info, philos[0], DEAD, RED) == -1)
		return (-1);
	return (0);
}
