#include "../includes/push_swap.h"

static void	sort_three(t_list **stack_a)
{
	t_list	*head_a;
	int		max;

	max = get_max_index(stack_a);
	head_a = *stack_a;
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
}
