#include "../includes/push_swap.h"

static void	sort_three(t_list **stack_a)
{
	int	max;

	max = get_max_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if (((*stack_a))->index == max)
	{
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else if (((*stack_a)->next->index == max))
	{
		sa(stack_a);
		ra(stack_a);
		if (!is_sorted(stack_a))
			sa(stack_a);
	}
	else
		sa(stack_a);
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->next->next->next->index == min)
		rra(stack_a);
	while ((*stack_a)->index != min)
		ra(stack_a);
	if ((*stack_a)->index == min)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		return ;
	}
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min_index(stack_a);
	if (is_sorted(stack_a))
		return ;
	if ((*stack_a)->next->next->next->next->index == min)
		rra(stack_a);
	while ((*stack_a)->index != min)
		ra(stack_a);
	if ((*stack_a)->index == min)
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
		return ;
	}
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
	int	size_lst;

	size_lst = ft_lstsize(*stack_a);
	if (size_lst == 2)
		sa(stack_a);
	if (size_lst == 3)
		sort_three(stack_a);
	if (size_lst == 4)
		sort_four(stack_a, stack_b);
	if (size_lst == 5)
		sort_five(stack_a, stack_b);
}
