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

void	free_info(t_info *info, t_philo *philos)
{
	free(philos);
	free(info->forks);
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
		info->nb_times_to_eat = 0;
	if (info->nb_philos < 0)
		return (err_msg(ARG1));
	if (info->time_to_die < 0)
		return (err_msg(ARG2));
	if (info->time_to_eat < 0)
		return (err_msg(ARG3));
	if (info->time_to_sleep < 0)
		return (err_msg(ARG4));
	if (info->nb_times_to_eat < 0)
		return (err_msg(ARG5));
	info->dead = false;
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philos;

	if (argc < 5 || argc > 6)
		return (err_msg(ARG0), 1);
	if (init_info(&info, argv) == -1)
		return (1);
	philos = create_philos(&info);
	if (philos == NULL)
		return (1);
	if (create_forks(&info) == -1)
		return (1);
	if (info.nb_philos == 1)
	{
		if (one_philo(&info, &philos) == -1)
			return (1);
	}
	else
	{
		if (create_threads(&info, &philos) == -1)
			return (1);
		// unlock_forks(&info);
		clean_forks(&info, info.nb_philos);
	}
	free_info(&info, &philos);
	return (0);
}
