/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_routine_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 17:23:31 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:47 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	routine_plus(t_var *ptr, char *str, int flag)
{
	sem_wait(ptr->print);
	printf("%ld  %lld %s\n", get_time(&ptr->current_time)
		- ptr->birth_time, ptr->id + 1, str);
	if (flag)
	{
		ptr->number_of_times_each_philosopher_must_eat -= 1;
		if (ptr->number_of_times_each_philosopher_must_eat == -3)
		{
			sem_post(ptr->print);
			exit(0);
		}
	}
	sem_post(ptr->print);
	return (1);
}

int	if_routine(t_var *ptr)
{
	if (!routine_plus(ptr, THINKING, 0))
		return (0);
	sem_wait(ptr->fork);
	if (!routine_plus(ptr, TFORK, 0))
		return (0);
	sem_wait(ptr->fork);
	if (!routine_plus(ptr, TFORK, 0))
		return (0);
	if (!routine_plus(ptr, EATING, 0))
		return (0);
	return (1);
}

void	*philos_routine(t_var *ptr)
{
	pthread_t	philo;

	sem_wait(ptr->thread_create);
	sem_wait(ptr->read);
	ptr->last_meal = get_time(&ptr->current_time);
	sem_post(ptr->read);
	if (pthread_create(&philo, NULL, &has_died, (void *)ptr))
		check_and_spawn_process(NULL, 1);
	sem_post(ptr->thread_create);
	while (TRUE)
	{
		if (!if_routine(ptr))
			break ;
		sem_wait(ptr->read);
		ptr->last_meal = get_time(&ptr->current_time);
		sem_post(ptr->read);
		ft_usleep(ptr->time_to_eat);
		sem_post(ptr->fork);
		sem_post(ptr->fork);
		if (!routine_plus(ptr, SLEEPING, SWITCH))
			break ;
		ft_usleep(ptr->time_to_sleep);
	}
	return (NULL);
}
