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
#include <limits.h>

int	err_msg(char *msg)
{
	write(2, msg, p_strlen(msg));
	return (-1);
}

int	init_info(t_info *info, char **argv)
{
	info->nb_philos = p_atoi(argv[1]);
	info->time_to_die = p_atoi(argv[2]);
	info->time_to_eat = p_atoi(argv[3]);
	info->time_to_sleep = p_atoi(argv[4]);
	if (argv[5])
		info->nb_times_to_eat = p_atoi(argv[5]);
	else
		info->nb_times_to_eat = INT_MAX;
	if (info->nb_philos == -1)
		return (err_msg(ARG1));
	if (info->time_to_die == -1)
		return (err_msg(ARG2));
	if (info->time_to_eat == -1)
		return (err_msg(ARG3));
	if (info->time_to_sleep == -1)
		return (err_msg(ARG4));
	if (info->nb_times_to_eat == -1)
		return (err_msg(ARG5));
	info->philos = (t_philo *)malloc(info->nb_philos * sizeof(t_philo));
	if (!info->philos)
		return (err_msg("Error: Malloc\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
		return (err_msg(ARG0), -1);
	if (init_info(&info, argv) == -1)
		return (-1);
	if (create_philos(&info) == -1)
		return (-1);
	pthread_join(info.philos[0].thread, NULL);
	pthread_join(info.philos[1].thread, NULL);
	return (0);
}
