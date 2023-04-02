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
	int			mult;
	int			i;

	i = 0;
	nb = 0;
	mult = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{	
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (*str - '0');
		i++;
	}
	if ((str[i] && (str[i] < '0' || str[i] > '9')) \
	|| (nb * mult < INT_MIN || nb * mult > INT_MAX))
		return (-1);
	return ((int)(nb * mult));
}


void	free_info(t_info *info)
{
	free(info->philos);
	free(info->forks);
}

int	err_msg(char *msg)
{
	write(2, "Error: ", 7);
	write(2, msg, p_strlen(msg));
	return (-1);
}

int	p_print(t_info *info, t_philo *philo, char *str, char *color)
{
	if (pthread_mutex_lock(info->msg))
		return (-1);
	printf("%s%ldphilo %d %s%s\n", get_time(), color, philo->id, str, END);
	if (pthread_mutex_unlock(info->msg))
		return (-1);
	return (0);
}