/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:34:47 by guvascon          #+#    #+#             */
/*   Updated: 2025/06/04 16:49:17 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int init_data(t_philo *philo, int ac, char **av)
{
	t_philo *philo;
	
	philo->num_philo = ft_atol(av[1]);
	if (philo->num_philo <= 0 || philo->num_philo > MAX_PHILO || \
		ft_isnbr(av[1]) == 1)
		return (write(2,"[ERROR]->PHILO\n", 16), 0);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	if(philo->time_to_die <= 0 || philo->time_to_eat <= 0 || \
		philo->time_to_sleep <= 0)
		return (0);
	if(pthread_mutex_init(&philo->print_mutex, NULL) != 0)
		return (0);
	return (1);
	if (ac == 5)
	{
		philo->num_times_to_eat = ft_atol(av[5]);
		if(philo->num_times_to_eat <= 0 || ft_isnbr(av[5]))
			return(write(2, "[ERROR]\n", 9), 0);
	else
		philo->num_times_to_eat = -1;
	}
}

int init_forks(t_data *data) //inicio os forks (mutex)
{
	int	i;
	
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (0);
	i = 0;
	while(i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}
