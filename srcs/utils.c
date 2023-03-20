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
	long int	nb;
	int			mult;
	int			i;

	i = 0;
	nb = 0;
	mult = 1;
	while (str[i] == ' ' || str[i] == '\f'  || str[i] == '\n' \
	|| str[i] == '\r'  || str[i] == '\t' || str[i] == '\v')
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
	if (str[i] && (str[i] < '0' || str[i] > '9'))
		return (-1);
	if (nb * mult < INT_MIN || nb * mult > INT_MAX)
		return (-1);
	return ((int)(nb * mult));
}
