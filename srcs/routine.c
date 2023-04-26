/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 16:51:20 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 11:52:37 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	working(t_info *info, int i)
{
	if (p_eat(info, &info->philos[i]) == false)
	{
		info->dead = true;
		return ;
	}
	if (p_think(info, &info->philos[i]) == false)
	{
		info->dead = true;
		return ;
	}
	if (p_sleep(info, &info->philos[i]) == false)
	{
		info->dead = true;
		return ;
	}
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

void	*payday(void *param)
{
	t_info	*info;

	info = (t_info *)param;
	if (pthread_mutex_lock(&info->msg))
		return (NULL);
	printf("bossman of %d\n", info->nb_philos);
	if (pthread_mutex_unlock(&info->msg))
		return (NULL);
	return (NULL);
}
