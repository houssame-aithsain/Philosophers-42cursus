/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:37:17 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:20:42 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define TRUE		1
# define SWITCH		9
# define THINKING 	"is thinking"
# define TFORK		"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"

typedef struct var{
	int				*usleep_breaker;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		id;
	long int		philo_numb;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*msg;
	pthread_mutex_t	*read;
	pthread_mutex_t	*usleep_m;
	struct timeval	current_time;
	long int		birth_time;
	long int		last_meal;
	long int		*eat_max;
	long int		number_of_times_each_philosopher_must_eat;
}	t_var;

typedef struct src{
	t_var			**ptr;
	long int		philos;
	int				i;
	int				usleep_breaker;
	pthread_t		*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg;
	pthread_mutex_t	read;
	pthread_mutex_t	usleep_m;
	struct timeval	main_time;
}	t_src;

int			ft_checker(int argc, char **argv);
int			if_valid(char c);
int			if_digit(char c);
int			main_thread_plus(t_src *src);
void		*philos_routine(void *arg);
int			mutex_fill(t_src *src, char **input);
int			ft_atoi(const char *str);
int			main_thread(t_src *src);
void		memory_free(t_src *src, int flag);
void		ft_mutex_destroy(t_src *src);
long int	get_time(struct timeval *current_time);
void		ft_usleep(long int duration_time, t_var *tmp);
int			ft_check_argv(char *str);

#endif