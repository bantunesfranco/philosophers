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

void	free_info(t_info *info, t_philo *philos, int mode)
{
	free(philos);
	if (info->forks)
	{
		if (mode == 0)
			clean_forks(philos, info, info->nb_philos, 0);
		free(info->forks);
	}
}

static int	init_info(t_info *info, char **argv)
{
	info->nb_philos = p_atoi(argv[1]);
	info->time_to_die = p_atoi(argv[2]);
	info->time_to_eat = p_atoi(argv[3]);
	info->time_to_sleep = p_atoi(argv[4]);
	if (argv[5])
		info->nb_meals = p_atoi(argv[5]);
	else
		info->nb_meals = 0;
	if (info->nb_philos <= 0 || info->nb_philos > 500)
		return (err_msg(ARG1));
	if (info->time_to_die <= 0)
		return (err_msg(ARG2));
	if (info->time_to_eat <= 0)
		return (err_msg(ARG3));
	if (info->time_to_sleep <= 0)
		return (err_msg(ARG4));
	if (info->nb_meals < 0)
		return (err_msg(ARG5));
	info->dead = false;
	info->philo_done = 0;
	info->forks = NULL;
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
	if (!philos)
		return (1);
	if (create_forks(&info, philos) == -1)
		return (free_info(&info, philos, 1), 1);
	create_threads(&info, philos);
	free_info(&info, philos, 0);
	return (0);
}
