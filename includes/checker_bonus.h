/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:10:14 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/14 14:31:34 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

char	*checker_moves(char *line, t_list **a, t_list **b);
void	ft_checker(char *line, t_list **a, t_list **b);
int		swaps(char *line, t_list **stack_a, t_list **stack_b);
int		push(char *line, t_list **stack_a, t_list **stack_b);
int		rotates(char *line, t_list **stack_a, t_list **stack_b);
int		rev_rotates(char *line, t_list **stack_a, t_list **stack_b);
int		ft_strcmp(char *s1, char *s2);

#endif
