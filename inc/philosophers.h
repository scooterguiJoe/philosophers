/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:58:54 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/22 16:31:22 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>

#define MAX_PHILO 200

typedef struct s_philo
{
	pthread_t	thread;
	int			number_of_philosophers;
	int			num_times_to_eat;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	
} 	t_philo;

//philo.c
 int init_data(t_philo *philo, char **av);

//philo_utils.c
int		ft_isdigit(char c);
int		ft_isnbr(char *nbr);
long	ft_atol(char *str);

#endif
