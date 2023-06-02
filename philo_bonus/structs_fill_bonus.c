/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_fill_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:38:12 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 01:47:25 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	fill_argv_five(int i, t_src *src, char **input)
{
	if (input[5])
	{
		src->ptr[i]->number_of_times_each_philosopher_must_eat
			= ft_atoi(input[5]);
	}
	else
		src->ptr[i]->number_of_times_each_philosopher_must_eat = -4;
}

void	struct_fill(t_src *src, char **input)
{
	long long			i;

	i = 0;
	gettimeofday(&src->main_time, NULL);
	while (i < src->philos)
	{
		src->ptr[i] = malloc(sizeof(t_var));
		src->ptr[i]->fork = src->fork;
		src->ptr[i]->print = src->print;
		src->ptr[i]->thread_create = src->thread_create;
		src->ptr[i]->read = src->read;
		src->ptr[i]->time_to_die = ft_atoi(input[2]);
		src->ptr[i]->time_to_eat = ft_atoi(input[3]);
		src->ptr[i]->time_to_sleep = ft_atoi(input[4]);
		src->ptr[i]->birth_time = (src->main_time.tv_sec * 1e6
				+ src->main_time.tv_usec) / 1000;
		fill_argv_five(i, src, input);
		src->ptr[i]->philo_numb = src->philos;
		src->ptr[i]->id = i;
		i++;
	}
}

void	semaphores_fill(t_src *src, char **input)
{
	src->philos = ft_atoi(input[1]);
	src->fork = sem_open("/fork", O_CREAT | O_EXCL, 0644, src->philos);
	src->thread_create = sem_open("/thread_create", O_CREAT | O_EXCL, 0644, 1);
	src->print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	src->read = sem_open("/read", O_CREAT | O_EXCL, 0644, 1);
	src->ps_id = malloc(sizeof(int) * src->philos);
	src->ptr = malloc(sizeof(t_var *) * src->philos);
	if (src->fork == SEM_FAILED || src->thread_create == SEM_FAILED
		|| src->print == SEM_FAILED || src->read == SEM_FAILED)
		ft_semaphore_error(src);
	struct_fill(src, input);
}
