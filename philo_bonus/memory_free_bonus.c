/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:52:20 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 01:52:25 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	memory_free(t_src *src)
{
	int	i;

	i = -1;
	while (++i < src->philos)
		free(src->ptr[i]);
	free(src->ptr);
	semaphores_destroy(src);
}

void	semaphores_destroy(t_src *src)
{
	sem_close(src->fork);
	sem_close(src->print);
	sem_close(src->thread_create);
	sem_close(src->read);
	sem_unlink("/fork");
	sem_unlink("/print");
	sem_unlink("/thread_create");
	sem_unlink("/read");
}
