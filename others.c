/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:15:48 by artmarti          #+#    #+#             */
/*   Updated: 2023/08/22 14:15:49 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_string_empty(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (!((argv[i] >= 9 && argv[i] <= 13) || argv[i] == 32))
			return (0);
		i++;
	}
	return (1);
}

int	b_sorted(t_list *a)
{
	while (a->next != NULL)
	{
		if ((a->data) > (a->next->data))
			return (1);
		a = a -> next;
	}
	return (0);
}

int	check_place_short(t_list *lst)
{
	int	nbr;
	int	place;
	int	i;

	i = 0;
	nbr = lst->data;
	place = 0;
	while (lst->next != NULL)
	{
		if ((lst->next->data) < (nbr))
		{
			nbr = lst->next->data;
			lst = lst->next;
			i++;
			place = i + 1;
		}
		else
		{
			lst = lst->next;
			i++;
		}
	}
	return (place);
}
