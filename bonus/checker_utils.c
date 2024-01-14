#include "../includes/checker.h"

char	*checker_moves(char *line, t_list **stack_a, t_list **stack_b)
{
	int	error;

	error = 0;
	if (line[0] == 's')
		error = swaps(line, stack_a, stack_b);
	else if (line[0] == 'p')
		error = push(line, stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'r')
		error = rev_rotates(line, stack_a, stack_b);
	else if (line[0] == 'r')
		error = rotates(line, stack_a, stack_b);
	if (error == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	return (get_next_line(0));
}

void	ft_checker(char *line, t_list **stack_a, t_list **stack_b)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = checker_moves(line, stack_a, stack_b);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!is_sorted(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

