/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:42 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/23 12:03:11 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	check_args(char **av)
{
	if(ft_atol(av[2]) <= 0|| ft_isnbr(av[2]))
		return(write(2, "[ERROR]->DYING\n", 16), 1);
	if(ft_atol(av[3]) <= 0 || ft_isnbr(av[3]))
		return(write(2, "[ERROR]->EATING\n", 17), 1);
	if(ft_atol(av[4]) <= 0 || ft_isnbr(av[4]))
		return(write(2, "[ERROR]->SLEEPING\n", 19), 1);
	if((av[5] && ft_atol(av[5]) <= 0) || ft_isnbr(av[5]))
		return(write(2, "[ERROR]->PHILO HAS TO EAT MORE\n", 32), 1);
	return(0);
}

int main(int ac, char **av)
{
	t_philo philo;

	if(ac < 5 || ac > 6)
		return(write(2, "[ERROR]->ARGS\n", 15), 0);
	if(check_args(av) == 1)
		return(1);
	init_data(&philo, av);
	return(0);
}