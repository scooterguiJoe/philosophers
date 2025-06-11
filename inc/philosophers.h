/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:58:54 by guvascon          #+#    #+#             */
/*   Updated: 2025/06/11 15:58:19 by guvascon         ###   ########.fr       */
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

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	int				num_philo;
	int				num_times_to_eat;
	int				philo_dead;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	size_t			last_meal;
	int				meals_eaten;
	//struct t_data			*data;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	print_mutex;
	size_t			start_time;
	pthread_mutex_t *forks;
	pthread_mutex_t death_mutex;
	t_philo *philo;
}	t_data;

# define MAX_PHILO 200
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
int init_data(t_philo *philo, int ac, char **av);
int init_forks(t_data *data);
void	destroy_forks(t_data *data);

//philo_utils.c
int		ft_isdigit(char c);
int		ft_isnbr(char *nbr);
long	ft_atol(char *str);

//philos_aux.c
size_t	get_current_time(void);
void	print_status(t_philo *philo, char *status);
void	ft_sleep(size_t ms);
void	assign_forks(t_data *data, int id, t_philo *philo);

//routine.c
void	*philo_routine(void *arg);
int should_stop(t_data *data);
void take_forks(t_philo *philo);
void update_meal(t_philo *philo);
void eat_sleep(t_philo *philo);

//monitor.c
void *monitor_routine(void *arg);
int simulation_should_end(t_data *data);

#endif
