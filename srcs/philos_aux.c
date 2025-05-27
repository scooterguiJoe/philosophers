/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:22:00 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/27 18:37:33 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

size_t	get_current_time(void)
{
	struct	timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}
void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print_mutex);
	if (!philo->data->philo_dead)
		printf("%zu %d %s", get_current_time() - philo->data->start_time, philo->id, status);
	pthread_mutex_unlock(&philo->data->print_mutex);	
}

// void	ft_sleep(size_t ms, t_philo *philo)
// {
// 	size_t	start;
// 	size_t	elapsed;
// 	size_t	remaining;
	
// 	start = get_current_time();
// 	while(1)
// 	{
// 		elapsed = get_current_time() - start;
// 		remaining = ms - elapsed;
// 		if(elapsed >= ms || philo->data->philo_dead)
// 			break;
// 		if (remaining > 1)
// 			usleep(remaining * 500);
// 		else
// 			usleep(50);
// 	}
// }

void ft_sleep(size_t ms)
{
	size_t	start;

	start = get_current_time();
	while(get_current_time() - start < ms)
		usleep(500); 
}