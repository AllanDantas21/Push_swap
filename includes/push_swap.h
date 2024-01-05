/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:03:22 by aldantas          #+#    #+#             */
/*   Updated: 2023/12/19 00:14:05 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

void	sort_big(t_list **stack_a, t_list **stack_b);
void	sort_small(t_list **stack_a, t_list **stack_b);
void	set_index(t_list **stack);
t_list	*get_next_min(t_list **stack);
int		get_max_index(t_list **stack);
int		get_min_index(t_list **stack);
int		is_sorted(t_list **stack);
void	check_args(char **argv, int argc);
void	print_values(t_list *stack);
void	ft_error(char *msg);
void	*ft_free(char **mat);

// Movimentos da push_swap
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

// funções de lista importadadas da libft
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	free_stack(t_list **stack);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int value);

#endif
