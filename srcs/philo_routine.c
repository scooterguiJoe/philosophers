/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:11:03 by guvascon          #+#    #+#             */
/*   Updated: 2025/06/04 16:46:37 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*philo_routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	if(philo->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&data->print_mutex);
		if(data->philo_dead)
		{
			pthread_mutex_unlock(&data->philo_dead);
			break ;
		}
		print_status(philo, THINKING);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, TAKEN_FORK);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, TAKEN_FORK);
		print_status(philo, EATING);
		philo->last_meal = get_current_time();
		ft_sleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_status(philo, SLEEPING);
		ft_sleep(philo->time_to_sleep);
	}
	return(NULL);
}


