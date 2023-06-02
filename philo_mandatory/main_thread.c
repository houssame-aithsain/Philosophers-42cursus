/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:27:32 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 00:17:39 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	if_valid(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	if_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_checker(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		printf("\033[31mError: Invalid arguments provided, try again.\n");
		return (0);
	}
	if ((argv[1] && !ft_atoi(argv[1])) || (argv[2] && !ft_atoi(argv[2]))
		|| (argv[5] && !ft_atoi(argv[5])) || (argv[3] && !ft_atoi(argv[3]))
		|| (argv[4] && !ft_atoi(argv[4])))
	{
		printf("\033[31mError: Invalid arguments provided, try again.\n");
		return (0);
	}
	while (argv && argv[i])
	{
		if (!ft_check_argv(argv[i++]))
		{
			printf("\033[31mError: Invalid arguments provided, try again.\n");
			return (0);
		}
	}
	return (1);
}

void	check_if_died(t_src	*src, int i)
{
	struct timeval	main_time;

	gettimeofday(&main_time, NULL);
	if ((main_time.tv_sec * 1000000 + main_time.tv_usec) / 1000
		- src->ptr[i]->last_meal >= src->ptr[i]->time_to_die
		&& src->ptr[i]->last_meal)
	{
		printf("%ld %lld died\n",
			(((main_time.tv_sec * 1000000)
					+ main_time.tv_usec) / 1000)
			- src->ptr[i]->birth_time, src->ptr[i]->id + 1);
		*src->ptr[i]->eat_max = 0;
		pthread_mutex_lock(&src->usleep_m);
		*src->ptr[i]->usleep_breaker = 0;
		pthread_mutex_unlock(&src->usleep_m);
		pthread_mutex_unlock(&src->msg);
	}
}

int	main_thread(t_src *src)
{
	int				i;

	i = 0;
	while (TRUE)
	{
		pthread_mutex_lock(&src->msg);
		pthread_mutex_lock(&src->read);
		check_if_died(src, i);
		pthread_mutex_unlock(&src->read);
		i = (i + 1) % src->ptr[0]->philo_numb;
		if (!*src->ptr[i]->eat_max)
		{
			pthread_mutex_unlock(&src->msg);
			pthread_mutex_unlock(&src->forks[i]);
			pthread_mutex_unlock(&src->forks[src->ptr[i]->id]);
			return (0);
		}
		pthread_mutex_unlock(&src->msg);
	}
	return (0);
}
