/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:52:20 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:23:08 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	memory_free(t_src *src, int flag)
{
	int	i;

	i = 0;
	if (flag)
	{
		printf("==>ERROR: Failed to initialize a mutex!<==\n");
		free(src->forks);
		free(src);
		return ;
	}
	ft_mutex_destroy(src);
	free(src->ptr[0]->eat_max);
	free(src->philo);
	free(src->forks);
	while (i < src->philos)
	{
		free(src->ptr[i++]);
	}
	free(src->ptr);
	free(src);
}

void	ft_mutex_destroy(t_src *src)
{
	int	i;

	i = 0;
	while (i < src->philos)
		pthread_mutex_destroy(&src->forks[i++]);
	pthread_mutex_destroy(&src->msg);
	pthread_mutex_destroy(&src->read);
	pthread_mutex_destroy(&src->usleep_m);
}
