/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/03 11:12:08 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	working(t_info *info, int i)
{
	printf("%d %d\n", info->nb_philos, i);
}

void	*work(void *param)
{
	t_info	*info;
	int		i;

	info = (t_info *)param;
	i = 0;
	if (info->time_to_eat > 0)
	{
		while (info->philos[i].nb_times_ate < info->nb_times_to_eat)
		{
			working(info, i);
		}
	}
	else
	{
		while (info->dead == false)
		{
			working(info, i);
		}
	}
	return (NULL);
}
