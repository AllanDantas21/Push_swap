/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 02:16:02 by aldantas          #+#    #+#             */
/*   Updated: 2024/01/11 00:26:15 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	ft_error(char *msg, char **args, int argc)
{
	if (argc == 2)
		ft_free((void **)args);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(0);
}

void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

static int	has_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	has_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_args(char **argv, int argc)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (has_duplicate(tmp, args, i))
			ft_error("Error\n", args, argc);
		if(!has_num(args[i]))
			ft_error("Error\n", args, argc);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error\n", args, argc);
		i++;
	}
	if (argc == 2)
		ft_free((void **)args);
}
