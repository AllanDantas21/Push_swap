
#include "../includes/push_swap.h"

static t_list **setup_stack(void)
{
	t_list	**tmp;

	tmp = (t_list **)malloc(sizeof(t_list));
	if(!tmp)
		return (NULL);
	*tmp = NULL;
	return (tmp);
}

static void	free_stacks(t_list **stack_a, t_list **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}

static void	check_sorted(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit (-1);
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if ((argc < 2))
		return (-1);
	if (argc == 2 && (count_nums(argv[1], ' ') == 1))
		return (-1);
	check_args(argv, argc);
	stack_a = setup_stack();
	stack_b = setup_stack();
	init_stack(stack_a, argc, argv);
	check_sorted(stack_a, stack_b);
	sort_stack(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}