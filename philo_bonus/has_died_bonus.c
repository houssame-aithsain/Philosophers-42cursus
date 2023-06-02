/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_died_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 21:41:26 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 00:08:54 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*has_died(void *arg)
{
	t_var				*ptr;
	struct timeval		main_time;

	ptr = (t_var *)arg;
	while (TRUE)
	{
		get_time(&main_time);
		sem_wait(ptr->read);
		if ((main_time.tv_sec * 1000000 + main_time.tv_usec) / 1000
			- ptr->last_meal >= ptr->time_to_die
			&& ptr->last_meal)
		{
			sem_wait(ptr->print);
			printf("%ld %lld died\n",
				(((main_time.tv_sec * 1000000)
						+ main_time.tv_usec) / 1000)
				- ptr->birth_time, ptr->id + 1);
			sem_post(ptr->read);
			exit(0);
			break ;
		}
		sem_post(ptr->read);
		usleep(1000);
	}
	return (NULL);
}
