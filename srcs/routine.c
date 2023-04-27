/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 17:52:24 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	working(t_info *info, int i)
{
	if (p_eat(info, i) == false)
		return (-1);
	if (info->philos[i].nb_times_ate != info->nb_times_to_eat)
	{
		if (p_think(info, i) == false)
			return (-1);
		if (p_sleep(info, i) == false)
			return (-1);
	}
	return (0);
}

void	*work(void *param)
{
	t_info	*info;
	int		i;

	info = (t_info *)param;
	i = info->nb_threads;
	if (info->nb_times_to_eat > 0)
	{
		while (info->philos[i].nb_times_ate < info->nb_times_to_eat \
		&& info->dead == false)
		{
			if (working(info, i) == -1)
				break ;
		}
	}
	else
	{
		while (info->dead == false)
		{
			if (working(info, i) == -1)
				break ;
		}
	}
	return (NULL);
}

void	*payday(void *param)
{
	t_info	*info;
	int		i;

	i = 0;
	info = (t_info *)param;
	if (info->nb_times_to_eat > 0)
	{
		while (info->philos[i].nb_times_ate < info->nb_times_to_eat \
		&& info->dead == false)
		{
			if (has_died(info, &i) == true)
				break ;
		}
	}
	else
	{
		while (info->dead == false)
		{
			if (has_died(info, &i) == true)
				break ;
		}
	}
	return (NULL);
}
