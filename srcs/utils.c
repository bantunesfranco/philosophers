/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/19 21:36:46 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/19 21:36:46 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <limits.h>

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

int	p_atoi(char *str)
{
	long long	nb;
	int			i;

	i = 0;
	nb = 0;
	if ((str[0] == '-' || str[0] == '+'))
	{	
		if (str[i] == '-')
			return (-1);
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
			if (nb < 0 || nb > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return ((int)nb);
}

int	err_msg(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, p_strlen(msg));
	return (-1);
}

int	p_print(t_info *info, t_philo *philo, char *str, char *color)
{
	int	dt;

	dt = delta_time(info->t0);
	if (info->dead == true)
		return (-1);
	if (pthread_mutex_lock(&info->msg))
		return (-1);
	if (info->dead == true)
	{
		pthread_mutex_unlock(&info->msg);
		return (-1);
	}
	else
		printf("%s%d\t%d %s%s\n", color, dt, philo->id, str, END);
	if (pthread_mutex_unlock(&info->msg))
		return (-1);
	return (0);
}
