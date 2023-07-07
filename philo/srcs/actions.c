/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/02 00:32:10 by bfranco       #+#    #+#                 */
/*   Updated: 2023/05/26 08:51:56 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	p_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&info->forks[philo->fl]);
	if (is_dead(philo, info) == true)
		return (pthread_mutex_unlock(&info->forks[philo->fl]), false);
	pthread_mutex_lock(&info->forks[philo->fr]);
	if (is_dead(philo, info) == true)
		return (pthread_mutex_unlock(&info->forks[philo->fl]), \
		pthread_mutex_unlock(&info->forks[philo->fr]), false);
	if (p_print(info, philo, FORK, GREEN) == -1 \
	|| p_print(info, philo, FORK, GREEN) == -1 \
	|| p_print(info, philo, EAT, BLUE) == -1)
		return (pthread_mutex_unlock(&info->forks[philo->fl]), \
		pthread_mutex_unlock(&info->forks[philo->fr]), false);
	philo->nb_times_ate++;
	philo->last_eat = get_time();
	do_task(info->time_to_eat);
	pthread_mutex_unlock(&info->forks[philo->fl]);
	pthread_mutex_unlock(&info->forks[philo->fr]);
	return (true);
}

bool	p_sleep(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, SLEEP, CYAN) == -1)
		return (false);
	do_task(info->time_to_sleep);
	return (true);
}

bool	p_think(t_info *info, t_philo *philo)
{
	if (p_print(info, philo, THINK, CYAN) == -1)
		return (false);
	return (true);
}

bool	is_dead(t_philo *philo, t_info *info)
{
	int	dt;
	// p_print(info, philo, "dead check", MAGENTA);
	dt = delta_time(philo->last_eat);
	printf("philo[%d]->dt = %d\n", philo->id, dt);
	if (dt >= info->time_to_die)
	{
		p_print(info, philo, DEAD, RED);
		pthread_mutex_lock(&info->death);
		info->dead = true;
		pthread_mutex_unlock(&info->death);
		return (true);
	}
	return (false);
}
