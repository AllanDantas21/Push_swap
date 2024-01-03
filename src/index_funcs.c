/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:19:20 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/03 02:18:23 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	set_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

int	get_max_index(t_list **stack)
{
	t_list	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->index;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min_index(t_list **stack)
{
	t_list	*tmp;
	int		min;

	tmp = *stack;
	min = tmp->index;
	while (tmp)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}

void	print_values(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
