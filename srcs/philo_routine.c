/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:11:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/06/11 15:58:43 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

// int	init_simulation(t_data *data, t_philo **philo)
// {
// 	int	i;

// 	i = 0;
// 	if(pthread_mutex_init(&data->print_mutex, NULL) != 0)
// 		return (0);
// 	if(!init_forks(data->num_philo))
// 	{
// 		pthread_mutex_destroy(&data->print_mutex);
// 		return (0);
// 	}
// 	*philo = malloc(sizeof(t_philo) * data->num_philo);
// 	if(!*philo)
// 	{
// 		destroy_forks(data);
// 		pthread_mutex_destroy(&data->print_mutex);
// 		return (0);
// 	}
// 	while(i < data->num_philo)
// 	{
// 		(*philo)[i].id = i + 1;
// 		(*philo)[i].data = data;
// 		assign_forks(&(*philo)[i], i, data);
		
// 	}
// 	return(1);
// } 
// void	*philo_routine(void *arg)
// {
// 	t_philo	*philo;
	
// 	philo = (t_philo *)arg;
// 	if(philo->id % 2 == 0)
// 		usleep(1500);
// 	while (1)
// 	{
// 		pthread_mutex_lock(&philo->data->print_mutex);
// 		if(philo->data->philo_dead)
// 		{
// 			pthread_mutex_unlock(&philo->data->philo_dead);
// 			break ;
// 		}
// 		print_status(philo, THINKING);
// 		pthread_mutex_lock(philo->left_fork);
// 		print_status(philo, TAKEN_FORK);
// 		pthread_mutex_lock(philo->right_fork);
// 		print_status(philo, TAKEN_FORK);
// 		print_status(philo, EATING);
// 		philo->last_meal = get_current_time();
// 		ft_sleep(philo->time_to_eat);
// 		pthread_mutex_unlock(philo->left_fork);
// 		pthread_mutex_unlock(philo->right_fork);
// 		print_status(philo, SLEEPING);
// 		ft_sleep(philo->time_to_sleep);
// 	}
// 	return(NULL);
// }

