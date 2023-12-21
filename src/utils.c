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
#include "../includes/minitalk.h"

void	set_index(t_list **stack)
{
	t_list	**head;
	int		index;

	index = 0;
	head = stack;
	while(head)
	{
		head->index = index++;
	}
}
