/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:12:15 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/14 14:15:34 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker_bonus.h"

int	swaps(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap_stack(stack_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap_stack(stack_b);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (1);
}

int	push(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push_stack(stack_a, stack_b);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push_stack(stack_b, stack_a);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (1);
}

int	rotates(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate_stack(stack_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate_stack(stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (1);
}

int	rev_rotates(char *lin, t_list **stack_a, t_list **stack_b)
{
	if (lin[0] == 'r' && lin[1] == 'r' && lin[2] == 'a' && lin[3] == '\n')
		rev_rotate_stack(stack_a);
	else if (lin[0] == 'r' && lin[1] == 'r' && lin[2] == 'b' && lin[3] == '\n')
		rev_rotate_stack(stack_b);
	else if (lin[0] == 'r' && lin[1] == 'r' && lin[2] == 'r' && lin[3] == '\n')
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		return (0);
	}
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (1);
}
