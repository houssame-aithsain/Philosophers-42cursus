/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:24:45 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:35:49 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_src	*src;

	if (!ft_checker(argc, argv))
		return (0);
	src = malloc(sizeof(t_src));
	if (!mutex_fill(src, argv))
		return (0);
	src->i = -1;
	while (++src->i < src->philos)
	{
		if (src->philos > 100)
			usleep(src->i);
		else
			usleep(200);
		if (pthread_create(&src->philo[src->i], NULL, &philos_routine,
				(void *)(src->ptr[src->i])))
			return (0);
	}
	src->i = -1;
	main_thread(src);
	while (++src->i < src->philos)
		if (pthread_join(src->philo[src->i], NULL))
			return (0);
	memory_free(src, 0);
	return (0);
}
