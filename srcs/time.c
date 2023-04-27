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

int	delta_time(int time)
{
	int	now;

	now = get_time();
	if (now == -1)
		return (-1);
	return (now - time);
}

void	do_task(int time)
{
	usleep(time * 1000);
}
