/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_hanlder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:53:18 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/01 18:23:32 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long int duration_time, t_var *tmp)
{
	struct timeval	old_time;
	struct timeval	current_time;

	gettimeofday(&old_time, NULL);
	if (!duration_time)
		return ;
	while (TRUE)
	{
		pthread_mutex_lock(tmp->usleep_m);
		if (!*tmp->usleep_breaker)
		{
			pthread_mutex_unlock(tmp->usleep_m);
			break ;
		}
		pthread_mutex_unlock(tmp->usleep_m);
		gettimeofday(&current_time, NULL);
		usleep(100);
		if (((current_time.tv_sec * 1000000 + current_time.tv_usec) / 1000)
			- ((old_time.tv_sec * 1000000 + old_time.tv_usec)
				/ 1000) >= duration_time)
			break ;
	}
}

long int	get_time(struct timeval *current_time)
{
	gettimeofday(current_time, NULL);
	return ((current_time->tv_sec * 1000000 + current_time->tv_usec) / 1000);
}
