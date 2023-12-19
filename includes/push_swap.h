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
#ifndef PUSH_SWAP.H
# define PUSH_SWAP.H

# include "../libft/libft.h"

typedef struct s_list
{
	int		value;
	int		index;
	struct s_list	*next;
}	t_list;

#endif
