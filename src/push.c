#include "../includes/push_swap.h"

int	push_stack(t_list **stack_dst, t_list **stack_src)
{
	t_list	*tmp;
	t_list	*head_dst;
	t_list	*head_src;

	if (ft_lstsize(*stack_src) == 0)
		return (-1);
	head_dst = *stack_dst;
	head_src = *stack_src;
	tmp = head_src;
	head_src = head_src->next;
	*stack_src = head_src;
	if (!head_dst)
	{
		
		head_dst = tmp;
		head_dst->next = NULL;
		*stack_dst = head_dst;
	}
	else
	{
		tmp->next = head_dst;
		*stack_dst = tmp;
	}
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push_stack(stack_a, stack_b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **stack_b, t_list **stack_a)
{
	if (push_stack(stack_b, stack_a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}
