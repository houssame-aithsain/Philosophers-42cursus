/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hait-hsa <hait-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:20:39 by hait-hsa          #+#    #+#             */
/*   Updated: 2023/04/09 01:39:20 by hait-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	if_valid(char c)
{
	if (c == '+')
		return (1);
	return (0);
}

int	check_if_outofrange(char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		k = 0;
		if (str[i] != 48 && (str[i] >= 48 && str[i] <= 57))
		{
			while (str[i] && str[i] >= 48 && str[i] <= 57)
			{
				if (k > 10)
					return (0);
				k++;
				i++;
			}	
		}
		i++;
	}
	return (1);
}

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!if_digit(str[i]) && !if_valid(str[i]))
			return (0);
		if (str[i] == '-')
			return (0);
		if (str[i] == '+')
		{
			if (!if_digit(str[i + 1]))
				return (0);
			if (!str[i - 1] && if_digit(str[i - 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_if_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (if_digit(str[i++]))
			return (1);
	}
	return (0);
}

int	ft_check_argv(char *str)
{
	if (!ft_check(str))
		return (0);
	if (!(check_if_empty(str)))
		return (0);
	if (!(check_if_outofrange(str)))
		return (0);
	return (1);
}
