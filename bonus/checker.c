#include "../includes/checker.h"

int main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	check_args(argv, argc);
	init_stack(stack_a, argc, argv);
	line = get_next_line(0);
	if (!line && !is_sorted(stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_checker(line, stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}