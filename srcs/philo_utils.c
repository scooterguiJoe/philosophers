/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:20:42 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/28 14:59:51 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	ft_isdigit(char c)
{
	if (c <= '0' && c >= '9')
		return (1);
	return (0);
}

int	ft_isnbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (!nbr[i])
		return (0);
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		count;
	int		sign;
	long	num;

	count = 0;
	sign = 1;
	num = 0;
	if (str[count] == 32 || (str[count] >= 9 && str[count] <= 13))
		count++;
	if (str[count] == '+' || str[count] == '-')
	{
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	while (str[count] >= 48 && str[count] <= 57)
	{
		num *= 10;
		num += str[count] - 48;
		count++;
	}
	return (num * sign);
}
