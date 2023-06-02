/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:31:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:38:23 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_src	*src;

	if (!ft_checker(argc, argv))
		return (0);
	check_and_spawn_process(NULL, SUNLINK);
	src = malloc(sizeof(t_src));
	semaphores_fill(src, argv);
	src->i = -1;
	while (++src->i < src->philos)
	{
		src->ps = fork();
		if (!src->ps)
		{
			usleep(200);
			philos_routine(src->ptr[src->i]);
		}
		else if (src->ps > 0)
			src->ps_id[src->i] = src->ps;
		else
		{
			check_and_spawn_process(src, SPS);
			return (0);
		}
	}
	check_and_spawn_process(src, WKILL);
}
