/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:58:42 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/22 17:01:38 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int init_data(t_philo *philo, char **av)
{
	philo->number_of_philosophers = ft_atol(av[1]);
	if(philo->number_of_philosophers <= 0 || philo->number_of_philosophers > MAX_PHILO)
	{
		printf("[ERROR]->PHILO\n");
		return(0);
	}
	return(1);
}

int main(int ac, char **av)
{
	t_philo philo;

	if(ac < 5 || ac > 6)
	{
		printf("[ERROR]->ARGS\n");
		return(0);
	}
	init_data(&philo, av);
	return(0);
}