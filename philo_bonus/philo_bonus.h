/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:14:33 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:34:05 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h>

# define SPS		0
# define TRUE		1
# define SUNLINK	2
# define WKILL		3
# define THINKING	"is thinking"
# define TFORK		"has taken a fork"
# define EATING		"is eating"
# define SLEEPING	"is sleeping"
# define SWITCH		9

typedef struct var{
	sem_t			*thread_create;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*read;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	long long		id;
	long int		philo_numb;
	struct timeval	current_time;
	long int		birth_time;
	long int		last_meal;
	long int		number_of_times_each_philosopher_must_eat;
}	t_var;

typedef struct src{
	t_var			**ptr;
	sem_t			*thread_create;
	sem_t			*print;
	sem_t			*fork;
	sem_t			*read;
	int				*ps_id;
	long int		philos;
	int				i;
	int				ps;
	struct timeval	main_time;
}	t_src;

void		ft_semaphore_error(t_src *src);
int			ft_checker(int argc, char **argv);
void		semaphores_destroy(t_src *src);
void		*has_died(void *arg);
int			if_valid(char c);
int			if_digit(char c);
void		*philos_routine(t_var *ptr);
void		semaphores_fill(t_src *src, char **input);
int			ft_atoi(const char *str);
void		memory_free(t_src *src);
void		ft_mutex_destroy(t_src *src);
long int	get_time(struct timeval *current_time);
void		ft_usleep(long int duration_time);
int			ft_check_argv(char *str);
void		check_and_spawn_process(t_src *src, int flag);

#endif
