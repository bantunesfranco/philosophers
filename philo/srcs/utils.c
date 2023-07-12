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
		return (-1);
	if (!p_strlen(str))
		return (-1);
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
	if (write(2, "Error: ", 7) == 1)
		return (-1);
	if (write(2, msg, p_strlen(msg)) == -1)
		return (-1);
	return (-1);
}

int	p_print(t_info *info, t_philo *philo, char *str, char *color)
{
	long long	dt;

	pthread_mutex_lock(&info->msg);
	pthread_mutex_lock(&info->death);
	if (info->dead == true)
	{
		pthread_mutex_unlock(&info->death);
		pthread_mutex_unlock(&info->msg);
		return (-1);
	}
	pthread_mutex_unlock(&info->death);
	dt = delta_time(info->t0);
	if (dt == -1)
		return (-1);
	printf("%s%lld\t%d %s %s\n", color, dt, philo->id, str, END);
	pthread_mutex_unlock(&info->msg);
	return (0);
}
