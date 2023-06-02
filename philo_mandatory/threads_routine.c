/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:19:14 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/07 19:53:06 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	routine_plus(t_var *tmp, char *str, int flag)
{
	pthread_mutex_lock(tmp->msg);
	if (!*tmp->eat_max)
	{
		pthread_mutex_unlock(tmp->read);
		pthread_mutex_unlock(&tmp->forks[(tmp->id + 1) % tmp->philo_numb]);
		pthread_mutex_unlock(&tmp->forks[tmp->id]);
		pthread_mutex_unlock(tmp->msg);
		return (0);
	}
	if (flag)
	{
		tmp->number_of_times_each_philosopher_must_eat -= 1;
		if (!tmp->number_of_times_each_philosopher_must_eat)
			*tmp->eat_max -= 1;
	}
	printf("%ld  %lld %s\n", get_time(&tmp->current_time)
		- tmp->birth_time, tmp->id + 1, str);
	pthread_mutex_unlock(tmp->msg);
	return (1);
}

int	if_routine(t_var *tmp)
{
	if (!routine_plus(tmp, THINKING, 0))
		return (0);
	pthread_mutex_lock(&tmp->forks[tmp->id]);
	if (!routine_plus(tmp, TFORK, 0))
		return (0);
	pthread_mutex_lock(&tmp->forks[(tmp->id + 1) % tmp->philo_numb]);
	if (!routine_plus(tmp, TFORK, 0))
		return (0);
	if (!routine_plus(tmp, EATING, 0))
		return (0);
	return (1);
}

void	*philos_routine(void *arg)
{
	t_var	*tmp;

	tmp = (void *)arg;
	pthread_mutex_lock(tmp->read);
	tmp->last_meal = get_time(&tmp->current_time);
	pthread_mutex_unlock(tmp->read);
	while (TRUE)
	{
		if (!if_routine(tmp))
			break ;
		pthread_mutex_lock(tmp->read);
		tmp->last_meal = get_time(&tmp->current_time);
		pthread_mutex_unlock(tmp->read);
		ft_usleep(tmp->time_to_eat, tmp);
		pthread_mutex_unlock(&tmp->forks[(tmp->id + 1) % tmp->philo_numb]);
		pthread_mutex_unlock(&tmp->forks[tmp->id]);
		if (!routine_plus(tmp, SLEEPING, SWITCH))
			break ;
		ft_usleep(tmp->time_to_sleep, tmp);
	}
	return (NULL);
}
