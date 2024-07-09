/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   very_and_short_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:21:40 by artmarti          #+#    #+#             */
/*   Updated: 2023/07/04 10:21:43 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swp_rot(t_list **lst, char c)
{
	ft_swap(lst, 'a');
	if (c == '1')
		ft_rotate(lst, 'a');
	else if (c == '2')
		ft_rev_rotate(lst, 'a');
}

void	very_short_list(t_list **lst)
{
	if (ft_lstsize(*lst) == 2)
	{
		if ((*lst)->data > (*lst)->next->data)
			ft_swap(lst, 'a');
		return ;
	}
	else if ((*lst)->data < (*lst)->next->data && 
		(*lst)->data < (*lst)->next->next->data)
		swp_rot(lst, '1');
	else if ((*lst)->data > (*lst)->next->data && 
		(*lst)->data < (*lst)->next->next->data)
		ft_swap(lst, 'a');
	else if ((*lst)->data > (*lst)->next->data && 
		(*lst)->data > (*lst)->next->next->data && 
		(*lst)->next->data < (*lst)->next->next->data)
		ft_rotate(lst, 'a');
	else if ((*lst)->data > (*lst)->next->data && 
		(*lst)->data > (*lst)->next->next->data)
		swp_rot(lst, '2');
	else
		ft_rev_rotate(lst, 'a');
}

void	short_list(t_list **lst)
{
	t_list	*new;

	new = NULL;
	while (ft_lstsize(*lst) > 3)
	{
		if (check_place_short(*lst) == 0)
			ft_push(lst, &new, 'b');
		else if (check_place_short(*lst) == ft_lstsize((*lst)))
		{
			ft_rev_rotate(lst, 'a');
			ft_push(lst, &new, 'b');
		}
		else if (check_place_short(*lst) < (ft_lstsize(*lst) / 2))
			ft_swap(lst, 'a');
		else
			ft_rotate(lst, 'a');
	}
	if (b_sorted(*lst) == 1)
		very_short_list(lst);
	if (b_sorted(new) == 1)
		very_short_list(&new);
	if (ft_lstsize(new) == 1)
		ft_push(&new, lst, 'a');
	else
		push_push(lst, new);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = check_place_short(*stack_a) - 1;
	if (distance == 1)
		ft_rotate(stack_a, 'a');
	else if (distance == 2)
	{
		ft_rotate(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (distance == 3)
		ft_rev_rotate(stack_a, 'a');
	if (b_sorted(*stack_a) == 0)
		return ;
	ft_push(stack_a, stack_b, 'b');
	very_short_list(stack_a);
	ft_push(stack_b, stack_a, 'a');
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int		distance;

	distance = check_place_short(*stack_a) - 1;
	if (distance == 1)
		ft_rotate(stack_a, 'a');
	else if (distance == 2)
	{
		ft_rotate(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else if (distance == 3)
	{
		ft_rev_rotate(stack_a, 'a');
		ft_rev_rotate(stack_a, 'a');
	}
	else if (distance == 4)
		ft_rev_rotate(stack_a, 'a');
	if (b_sorted(*stack_a) == 0)
		return ;
	ft_push(stack_a, stack_b, 'b');
	sort_4(stack_a, stack_b);
	ft_push(stack_b, stack_a, 'a');
}
