/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:29:48 by artmarti          #+#    #+#             */
/*   Updated: 2023/06/09 15:30:08 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **a)
{
	t_list	*b;

	b = NULL;
	if (b_sorted(*a) != 0)
	{
		if (ft_lstsize(*a) == 1)
			return ;
		else if (ft_lstsize(*a) <= 3)
			very_short_list(a);
		else if (ft_lstsize(*a) == 4)
			sort_4(a, &b);
		else if (ft_lstsize(*a) == 5)
			sort_5(a, &b);
		else
			long_list(a);
	}
}

void	free_list(t_list *list)
{
	t_list	*temp;

	while (list != NULL)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

int	argc2(int i, char **argv, t_list *nv)
{
	t_list	*a;
	int		y;

	if (ft_check2(argv[1]) == 1)
		return (1);
	i = ft_wordcount(argv[1], ' ');
	y = i - 1;
	argv = ft_split(argv[1], ' ');
	if (ft_check(argv) == 1)
		return (1);
	a = NULL;
	while (i-- != 0)
	{
		nv = malloc(sizeof(t_list));
		if (!nv)
			return (1);
		nv->data = ft_atoi(argv[y]);
		nv->next = a;
		a = nv;
		y--;
	}
	push_swap(&nv);
	free_list(nv);
	free_argv(argv);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*nouveau;

	nouveau = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		if (argc2(argc, argv, nouveau) == 1)
			return (0);
	if (argc == 2 || ft_check(argv) == 1)
		return (0);
	a = NULL;
	while (--argc != 0)
	{
		nouveau = malloc(sizeof(t_list));
		if (!nouveau)
			return (0);
		nouveau->data = ft_atoi(argv[argc]);
		nouveau->next = a;
		a = nouveau;
	}
	push_swap(&nouveau);
	free_list(nouveau);
	return (0);
}
