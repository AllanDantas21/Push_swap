/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:16:13 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/14 14:17:42 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/checker_bonus.h"

static t_list	**setup_stack(void)
{
	t_list	**tmp;

	tmp = (t_list **)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	*tmp = NULL;
	return (tmp);
}

static void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if ((argc < 2) || (argc == 2 && !argv[1][0]))
		return (-1);
	check_args(argv, argc);
	stack_a = setup_stack();
	stack_b = setup_stack();
	init_stack(stack_a, argc, argv);
	line = get_next_line(0);
	if (!line && !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_checker(line, stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
