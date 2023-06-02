/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:38:12 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:22:11 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_argv_five(int i, t_src *src, char **input, long int *eat_max)
{
	src->usleep_breaker = 1;
	if (input[5])
	{
		src->ptr[i]->number_of_times_each_philosopher_must_eat
			= ft_atoi(input[5]);
		*eat_max = ft_atoi(input[1]);
		src->ptr[i]->eat_max = eat_max;
	}
	else
	{
		src->ptr[i]->eat_max = eat_max;
		src->ptr[i]->number_of_times_each_philosopher_must_eat = -1;
	}
}

void	struct_fill(t_src *src, char **input)
{
	long int	*eat_max;
	int			i;

	i = 0;
	eat_max = malloc(sizeof(int));
	*eat_max = -1;
	gettimeofday(&src->main_time, NULL);
	while (i < src->philos)
	{
		src->ptr[i] = malloc(sizeof(t_var));
		src->ptr[i]->forks = &(*src->forks);
		src->ptr[i]->msg = &src->msg;
		src->ptr[i]->read = &src->read;
		src->ptr[i]->usleep_m = &src->usleep_m;
		src->ptr[i]->time_to_die = ft_atoi(input[2]);
		src->ptr[i]->time_to_eat = ft_atoi(input[3]);
		src->ptr[i]->time_to_sleep = ft_atoi(input[4]);
		src->ptr[i]->birth_time = (src->main_time.tv_sec * 1e6
				+ src->main_time.tv_usec) / 1000;
		fill_argv_five(i, src, input, eat_max);
		src->ptr[i]->philo_numb = src->philos;
		src->ptr[i]->id = i;
		src->ptr[i]->usleep_breaker = &src->usleep_breaker;
		i++;
	}
}

int	mutex_fill(t_src *src, char **input)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&src->msg, NULL)
		|| pthread_mutex_init(&src->usleep_m, NULL)
		|| pthread_mutex_init(&src->read, NULL))
	{
		free(src);
		return (0);
	}
	src->philos = ft_atoi(input[1]);
	src->forks = malloc(sizeof(pthread_mutex_t) * src->philos);
	while (i < src->philos)
	{
		if (pthread_mutex_init(&src->forks[i++], NULL))
		{
			memory_free(src, 1);
			return (0);
		}
	}
	i = 0;
	src->philo = malloc(sizeof(pthread_t) * src->philos);
	src->ptr = malloc(sizeof(t_var *) * src->philos);
	struct_fill(src, input);
	return (1);
}
