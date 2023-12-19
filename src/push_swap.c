/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:32:54 by aldantas          #+#    #+#             */
/*   Updated: 2023/12/18 22:51:24 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"
void	init_stack(t_list **stack, int argc, char **argv)
{
	//Função para passar os argumentos do argv para a stack_a;
}


int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	
	if(argc < 2)
		return (-1);	/*verificar se a entrada de args é menos que 2*/
	//checar se os argumentos são validos -> sinal duplo, repetição e etc;
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv); /*-> iniciar a stack_a */
	sort_stack(stack_a, stack_b); /* função que vai fazer o sort das duas stacks */
	free_stack(stack_a); /* liberar as stacks na heap */
	free_stack(stack_b);
	return(0);
}
