/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_spawn_process_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:07:05 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 17:33:51 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	if_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_semaphore_error(t_src *src)
{
	int	i;

	i = 0;
	printf("==>ERROR: Failed to open a semaphore!<==\n");
	while (i < src->philos)
		free(src->ptr[i++]);
	free(src->ptr);
	free(src->ps_id);
	free(src);
	exit(0);
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

void	ft_waitpid(t_src *src)
{
	int	status;

	status = -1;
	{
		src->i = -1;
		waitpid(-1, &status, 0);
		if (!status)
		{
			memory_free(src);
			while (src->philos--)
				kill(src->ps_id[src->philos], SIGINT);
			free(src->ps_id);
			free(src);
		}
	}
}

void	check_and_spawn_process(t_src *src, int flag)
{
	if (!flag)
	{
		sem_wait(src->print);
		printf("==>ERROR: Failed to fork a process!<==\n");
		while (src->philos--)
			kill(src->ps_id[src->philos], SIGINT);
		memory_free(src);
		free(src->ps_id);
		free(src);
	}
	else if (flag == 1)
	{
		sem_wait(src->print);
		printf("==>ERROR: Failed to create a thread!<==\n");
		exit(0);
	}
	else if (flag == 2)
	{
		sem_unlink("/fork");
		sem_unlink("/print");
		sem_unlink("/thread_create");
		sem_unlink("/read");
	}
	else
		ft_waitpid(src);
}
