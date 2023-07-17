/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eat.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/13 17:12:15 by bfranco       #+#    #+#                 */
/*   Updated: 2023/07/17 08:49:12 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	min_meals(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&philo->eat);
	if (info->nb_meals > 0 && philo->nb_times_ate == info->nb_meals)
		info->philo_done++;
	pthread_mutex_unlock(&philo->eat);
}

static void	drop_forks(t_info *info, t_philo *philo)
{
	pthread_mutex_unlock(&info->forks[philo->fr]);
	pthread_mutex_unlock(&info->forks[philo->fl]);
}

static bool	pickup_forks(t_info *info, t_philo *philo)
{
	if (is_end(info) == true)
		return (false);
	pthread_mutex_lock(&info->forks[philo->fl]);
	if (is_end(info) == true || p_print(info, philo, FORK, GREEN) == -1)
	{
		pthread_mutex_unlock(&info->forks[philo->fl]);
		return (false);
	}
	pthread_mutex_lock(&info->forks[philo->fr]);
	if (is_end(info) == true || p_print(info, philo, FORK, GREEN) == -1)
	{
		pthread_mutex_unlock(&info->forks[philo->fr]);
		pthread_mutex_unlock(&info->forks[philo->fl]);
		return (false);
	}
	return (true);
}

bool	p_eat(t_info *info, t_philo *philo)
{
	if (pickup_forks(info, philo) == false)
		return (false);
	if (p_print(info, philo, EAT, BLUE) == -1)
	{
		pthread_mutex_unlock(&info->forks[philo->fr]);
		pthread_mutex_unlock(&info->forks[philo->fl]);
		return (false);
	}
	pthread_mutex_lock(&philo->eat);
	philo->nb_times_ate++;
	philo->last_eat = get_time();
	pthread_mutex_unlock(&philo->eat);
	ft_usleep(info->time_to_eat);
	drop_forks(info, philo);
	min_meals(philo, info);
	return (true);
}
