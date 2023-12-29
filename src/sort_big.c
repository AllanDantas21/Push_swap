#include "../includes/push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

static int	get_max_bits(t_list **stack)
{
	int		max_bits;
	int		max;
	max = get_max_index(stack);
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	sort_stack_b(t_list **stack_a, t_list **stack_b, int size, int max_bits, int j)
{
	while (size-- && j <= max_bits && !is_sorted(stack_a))
	{
		if ((((*stack_b)->index >> j) & 1) == 0)
			ra(stack_b);
		else
			pa(stack_a, stack_b);
	}
	if (is_sorted(stack_a))
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int	j;
	int	max_bits;
	int	size;

	max_bits = get_max_bits(stack_a);
	size =ft_lstsize(*stack_a);
	j = 0;
	while (j <= max_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size-- && !is_sorted(stack_a))
		{
			if ((((*stack_a)->index >> j) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
		}
		sort_stack_b(stack_a, stack_b, ft_lstsize(*stack_b), max_bits, j + 1);
		j++;
	}
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}