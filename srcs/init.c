/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:34:47 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/23 15:53:10 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int init_data(t_philo *philo, char **av)
{
	philo->number_of_philosophers = ft_atol(av[1]);
	if(philo->number_of_philosophers <= 0 || philo->number_of_philosophers > MAX_PHILO || 
		ft_isnbr(av[1]) == 1)
		return(write(2,"[ERROR]->PHILO\n", 16), 0);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	if(av[5])
		philo->num_times_to_eat = ft_atol(av[5]);
	else
		philo->num_times_to_eat = -1;
	return(1);
}

int init_forks(t_philo *philo)
{
	int	i;
	pthread_mutex_t *forks;
	
	forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	if(!forks)
		return(0);
	i = 0;
	while(i < )
}