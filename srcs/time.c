/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 14:33:22 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/19 14:33:22 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (err_msg("Error: get_time"), -1);
	return (time.tv_sec * 1000 + time.tv_usec * 0.001);
}

int	delta_time(t_info *info)
{
	int	time;

	time = get_time();
	if (time == -1)
		return (-1);
	return (time - info->t0);
}
