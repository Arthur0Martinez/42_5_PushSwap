/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 11:42:52 by artmarti          #+#    #+#             */
/*   Updated: 2023/06/14 11:42:56 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **pile, char c)
{
	t_list	*temp;

	if ((*pile)->next == NULL || *pile == NULL)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	temp->next = (*pile)->next;
	(*pile)->next = temp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	ft_push(t_list **a, t_list **b, char c)
{
	t_list	*temp;

	temp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, temp);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	ft_rotate(t_list **pile, char c)
{
	t_list	*temp;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	temp = *pile;
	*pile = (*pile)->next;
	ft_lstadd_back(pile, temp);
	temp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	ft_rev_rotate(t_list **pile, char c)
{
	t_list	*temp;
	t_list	*end;

	if (*pile == NULL || (*pile)->next == NULL)
		return ;
	end = ft_lstlast(*pile);
	temp = *pile;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(pile, end);
	temp->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}

int	ft_check2(char *argv)
{
	if (ft_check_string(argv) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
