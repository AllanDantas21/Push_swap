#include "../includes/checker.h"

char	*checker_moves(char *line, t_list **stack_a, t_list **stack_b)
{
	if (line[0] == 's')
		swaps(line, stack_a, stack_b);
	else if (line[0] == 'p')
		push(line, stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'r')
		rev_rotates(line, stack_a, stack_b);
	else if (line[0] == 'r')
		rotates(line, stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
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