/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/02 16:51:20 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	work(void *param)
{
	const t_info	*info = (t_info *)param;
	int				int;

	if (info->time_to_eat > 0)
	{
		while (info->philos[i].nb_times_ate < info->nb_times_to_eat)
		{
			working(info, i);
		}
	}
	else
	{

	}
}