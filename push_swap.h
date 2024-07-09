/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:35:34 by artmarti          #+#    #+#             */
/*   Updated: 2023/06/09 15:35:36 by artmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	int				data;
	int				index;
}	t_list;

t_list	*ft_lstlast(t_list *lst);

int		set_index(t_list **lst);
int		b_sorted(t_list *a);
int		ft_lstsize(t_list *lst);
int		ft_check_others(char **argv);
int		ft_check_error(char **argv);
int		main(int argc, char **argv);
int		ft_check_string(char *argv);
int		ft_strcmp(const char *s1, const char *s2);
int		check_place_short(t_list *lst);
int		ft_wordcount(char const *s, char c);
int		ft_check(char **argv);
int		ft_check_string_empty(char *argv);
int		ft_check2(char *argv);
long	ft_atoi(char *nptr);
void	ft_rev_rotate(t_list **pile, char c);
void	ft_swap(t_list **pile, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_rotate(t_list **pile, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	long_list(t_list **lst);
void	tester_index(t_list *new);
void	ft_push(t_list **a, t_list **b, char c);
void	push_swap(t_list **a);
void	push_push(t_list **lst, t_list *new);
void	very_short_list(t_list **lst);
void	short_list(t_list **lst);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
