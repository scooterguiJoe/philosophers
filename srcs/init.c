/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 11:34:47 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/28 15:04:18 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int init_data(t_philo *philo, char **av)
{
	philo->number_of_philosophers = ft_atol(av[1]);
	if (philo->number_of_philosophers <= 0 || philo->number_of_philosophers > MAX_PHILO || 
		ft_isnbr(av[1]) == 1)
		return (write(2,"[ERROR]->PHILO\n", 16), 0);
	philo->time_to_die = ft_atol(av[2]);
	philo->time_to_eat = ft_atol(av[3]);
	philo->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		philo->num_times_to_eat = ft_atol(av[5]);
	else
		philo->num_times_to_eat = -1;
	return (1);
}

int init_forks(t_philo *philo) //inicio os forks (mutex)
{
	int				i;
	pthread_mutex_t	*forks;
	
	
	forks = malloc(sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	if (!forks)
		return (0);
	i = 0;
	while(i < philo->number_of_philosophers)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
		{
			while (i-- > 0)
				pthread_mutex_destroy(&forks[i]);
			free(forks);
			return (0);
		}
		i++;
	}
	i = 0;
	while(i < philo->number_of_philosophers)
	{
		philo[i].left_fork = &forks[i];
		philo[i].right_fork = &forks[(i + 1) % philo->number_of_philosophers];
		i++;
	}
	return (1);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	while (!philo->data->philo_dead)
	{
		print_status(philo, "is thinking");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		print_status(philo, "is eating");
		philo->last_meal = get_current_time();
		ft_sleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_status(philo, "is sleeping");
		ft_sleep(philo->time_to_sleep);
	}
	return(NULL);
}
