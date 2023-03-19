/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 15:21:49 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/19 15:21:49 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	p_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

void	err_msg(char *msg)
{
	write(2, msg, p_strlen(msg));
}

int	init_info(t_info *info, char **argv)
{
	info->nb_philos = p_atoi(argv[1]);
	info->time_to_die = p_atoi(argv[2]);
	info->time_to_eat = p_atoi(argv[3]);
	info->time_to_sleep = p_atoi(argv[4]);
	info->nb_times_to_eat = p_atoi(argv[5]);
	if (info->nb_philos == -1 || info->time_to_die == -1 \
	|| info->time_to_eat == -1 || info->time_to_sleep == -1 \
	|| info->nb_times_to_eat == -1)
	return (0);
}

int main(int argc, char **argv)
{
	t_info	info;

	if (argc != 5 || argc != 6)
		return (err_msg(ARG0), -1);
	if (init_info(&info, argv) == -1)
		return (-1);
	return (0);
}