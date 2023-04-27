/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philos.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 10:47:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 11:44:15 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	create_philos(t_info *info)
{
	int			i;
	int			j;

	info->philos = (t_philo *)malloc(info->nb_philos * sizeof(t_philo));
	if (!info->philos)
		return (err_msg("Malloc\n"));
	i = 0;
	while (i < info->nb_philos)
	{
		j = i + 1;
		if (i == info->nb_philos - 1)
			j = 0;
		info->philos[i].id = i + 1;
		info->philos[i].nb_times_ate = 0;
		info->philos[i].time_to_die = 0;
		info->philos[i].fork.left = i;
		info->philos[i].fork.right = j;
		i++;
	}
	return (0);
}

int	one_philo(t_info *info)
{
	info->t0 = get_time();
	p_print(info, &info->philos[0], FORK, GREEN);
	do_task(info->time_to_die);
	p_print(info, &info->philos[0], DEAD, RED);
	return (0);
}