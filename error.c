/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:42:35 by artmarti          #+#    #+#             */
/*   Updated: 2023/06/14 11:42:38 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_string2(char *argv, int i)
{
	if (argv[i] == '-')
		return (1);
	if (!(argv[i] >= '0' && argv[i] <= '9'))
	{
		if ((argv[i] >= 9 && argv[i] <= 13) || 
			argv[i] == 32 || argv[i] == '\0')
			return (2);
		else 
			return (1);
	}
	return (0);
}

int	ft_check_string(char *argv)
{
	int	i;

	i = 0;
	if (ft_check_string_empty(argv) == 1)
		return (1);
	while (argv[i])
	{
		while ((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32)
			i++;
		while (!(argv[i] >= 9 && argv[i] <= 13) || (!(argv[i] == 32)))
		{
			if (ft_check_string2(argv, i) == 1)
			{
				if (!(argv[i + 1] >= '0' && argv[i + 1] <= '9'))
					return (1);
				i++;
			}
			else if (ft_check_string2(argv, i) == 2)
				break ;
			i++;
		}
	}
	return (0);
}

int	ft_check_others(char **argv)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	while (argv[i])
	{
		while ((argv[i][y] >= 9 && argv[i][y] <= 13) || argv[i][y] == 32)
			y++;
		if (argv[i][y] == '-')
		{
			if (!(argv[i][y + 1] >= '0' && argv[i][y + 1] <= '9'))
				return (1);
			y++;
		}
		while (argv[i][y] != '\0')
		{
			if (!(argv[i][y] >= '0' && argv[i][y] <= '9'))
				return (1);
			y++;
		}
		y = 0;
		i++;
	}
	return (0);
}

int	ft_check_error(char **argv)
{
	int	i;
	int	y;

	if (ft_check_others(argv) == 1)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) > 2147483647 || ft_atoi(argv[i]) < -2147483648)
			return (1);
		y = 0;
		while (argv[y])
		{
			if (argv[i + 1] == NULL && i == y)
				break ;
			if (y == i && (argv[i + 1] != NULL))
				y++;
			if (ft_strcmp(argv[i], argv[y]) == 0)
				return (1);
			y++;
		}
		i++;
	}
	return (0);
}

int	ft_check(char **argv)
{
	if (ft_check_error(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else if (ft_check_others(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
		return (0);
}
