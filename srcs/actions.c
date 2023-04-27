/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/04/26 17:55:43 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, int i)
{
	if (pthread_mutex_lock(&info->forks[info->philos[i].fork.left]))
		return (false);
	if (p_print(info, &info->philos[i], FORK, GREEN) == -1)
		return (false);
	if (pthread_mutex_lock(&info->forks[info->philos[i].fork.right]))
		return (false);
	if (p_print(info, &info->philos[i], FORK, GREEN) == -1)
		return (false);
	if (p_print(info, &info->philos[i], EAT, GREEN) == -1)
		return (false);
	info->philos[i].time_to_die = get_time();
	do_task(info->time_to_eat);
	info->philos[i].nb_times_ate++;
	if (pthread_mutex_unlock(&info->forks[info->philos[i].fork.left]))
		return (false);
	if (pthread_mutex_unlock(&info->forks[info->philos[i].fork.right]))
		return (false);
	return (true);
}

bool	p_sleep(t_info *info, int i)
{
	if (p_print(info, &info->philos[i], SLEEP, GREEN) == -1)
		return (false);
	do_task(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, int i)
{
	if (p_print(info, &info->philos[i], THINK, GREEN) == -1)
		return (false);
	return (true);
}

bool	has_died(t_info *info, int *i)
{
	int	dt;
	
	dt = delta_time(info->philos[*i].time_to_die);
	if (*i == info->nb_philos)
		*i = 0;
	if (dt > info->time_to_die)
	{
		p_print(info, &info->philos[*i], DEAD, RED);
		info->dead = true;
		return (true);
	}
	i++;
	return (false);
}
