/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:19:20 by aldantas          #+#    #+#             */
/*   Updated: 2023/12/19 00:28:36 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while(head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	set_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = *stack;
	while(head)
	{
		head->index = index++;
	}
}

void	print_values(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
	while(tmp != NULL)
	{
		ft_putnbr_fd(tmp->value, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}
