/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:35:33 by artmarti          #+#    #+#             */
/*   Updated: 2023/06/29 10:35:35 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_list **lst)
{
	t_list	*lst2;
	t_list	*temp;
	int		index;
	int		res;

	res = 0;
	lst2 = (*lst);
	while (lst2 != NULL)
	{
		lst2->index = 0;
		index = 0;
		temp = (*lst);
		while (temp != NULL)
		{
			if (lst2->data >= temp->data)
				lst2->index = index++;
			temp = temp->next;
		}
		lst2 = lst2->next;
		if (index > res)
			res = index;
	}
	return (res);
}

void	long_list_size(t_list **lst, int j, int size, int i)
{
	t_list	*new;
	int		nbr;

	nbr = 0;
	new = NULL;
	while (j < size)
	{
		nbr = (*lst)->index;
		if (((nbr >> i) & 1) == 1)
			ft_rotate(lst, 'a');
		else
			ft_push(lst, &new, 'b');
		j++;
	}
	j = 0;
	while (ft_lstsize(new) > 0)
		ft_push(&new, lst, 'a');
}

void	long_list(t_list **lst)
{
	int		size;
	int		max_bits;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = set_index(lst);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{
		long_list_size(lst, j, size, i);
		i++;
	}
}

void	push_push(t_list **lst, t_list *new)
{
	ft_swap(&new, 'b');
	ft_push(&new, lst, 'a');
	ft_push(&new, lst, 'a');
}
