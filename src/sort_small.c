#include "../includes/push_swap.h"

static void	sort_three(t_list **stack_a)
{
	t_list	*head_a;
	int		max;

	max = get_max_index(stack_a);
	head_a = *stack_a;
	if (is_sorted(stack_a))
		return ;
	if ((head_a->index == max))
	{
		ra(stack_a);
		if(!is_sorted(stack_a))
			sa(stack_a);
	}
	else if ((head_a->next->index == max))
	{
		sa(stack_a);
		ra(stack_a);
		if(!is_sorted(stack_a))
			sa(stack_a);
	}
	else 
		sa(stack_a);
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;

	head_a = *stack_a;
	if (head_a->next->next->next->index == 0)
	{
		rra(stack_a);
		head_a = *stack_a;
	}
	while (head_a->index != 0)
	{
		ra(stack_a);
		head_a = *stack_a;
	}
	if (head_a->index == 0)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
		return ;
	}
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
 	(void)stack_b;
	return ;
}

void	sort_small(t_list **stack_a, t_list **stack_b)
{
 	(void)stack_a;
 	(void)stack_b;
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