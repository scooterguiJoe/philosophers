/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:34:47 by guvascon          #+#    #+#             */
/*   Updated: 2025/06/11 16:18:09 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int init_data(t_philo *philo, int ac, char **av)
{	
	
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
	// if(pthread_mutex_init(&philo->print_mutex, NULL) != 0)
	// 	return (0);
	if (ac == 6)
	{
		philo->num_times_to_eat = ft_atol(av[5]);
		if(philo->num_times_to_eat <= 0)
			return(write(2, "[ERROR]\n", 9), 0);
	}
	else
			philo->num_times_to_eat = -1;
	return (1);
}

// static int init_philosophers(t_philo *philo, t_data *data)
// {
// 	int i;

// 	i = 0;
// 	while (i < data->num_philo)
// 	{
// 		philo[i].id = i + 1;
// 		philo[i].data = data;
// 		assign_forks(&philo[i], i, data);
// 		philo[i].last_meal = data->start_time;
// 		philo[i].meals_eaten = 0;
// 		philo[i].time_to_die = philo->time_to_die;
// 		philo[i].time_to_eat = philo->time_to_eat;
// 		philo[i].time_to_sleep = philo->time_to_sleep;
// 		philo[i].num_times_to_eat = philo->num_times_to_eat;
// 		i++;
// 	}
// 	return (1);
// }

// int init_forks(t_data *data) //inicio os forks (mutex)
// {
// 	int	i;
	
// 	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
// 	if (!data->forks)
// 		return (0);
// 	i = 0;
// 	while(i < data->forks)
// 	{
// 		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
// 		{
// 			while (i-- > 0)
// 				pthread_mutex_destroy(&data->forks[i]);
// 			free(data->forks);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// void	destroy_forks(t_data *data)
// {
// 	int i;
	
// 	if (data->forks)
// 	{
// 		i = 0;
// 		while (i < data->num_philo)
// 		{
// 			pthread_mutex_destroy(&data->forks[i]);
// 			i++;
// 		}
// 		free(data->forks);
// 		data->forks = NULL;
// 	}
// }
