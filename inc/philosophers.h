/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:58:54 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/28 15:25:31 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>

#define MAX_PHILO 200

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				number_of_philosophers;
	int				num_times_to_eat;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	size_t			last_meal;
	int				meals_eaten;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				philo_dead;
	pthread_mutex_t	print_mutex;
	size_t			start_time;
	pthread_mutex_t *forks;
	
}	t_data;

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"


# define THINKING	BLUE "is thinking" RESET
# define TAKEN_FORK	GREEN "has taken a fork" RESET
# define EATING		MAGENTA "is eating" RESET
# define SLEEPING	CYAN "is sleeping" RESET
# define DIED		RED "died" RESET

//philo.c
int	check_args(char **av);

//init.c
int init_data(t_philo *philo, char **av);
int init_forks(t_philo *philo);
//void	*philo_routine(void *arg);

//philo_utils.c
int		ft_isdigit(char c);
int		ft_isnbr(char *nbr);
long	ft_atol(char *str);

//philos_aux.c
size_t	get_current_time(void);
void	print_status(t_philo *philo, char *status);
void	ft_sleep(size_t ms);

#endif
