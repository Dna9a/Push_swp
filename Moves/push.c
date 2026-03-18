#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
		return ;
	ft_push_stack(stack_a, ft_pop_stack(stack_b));
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ;
	ft_push_stack(stack_b, ft_pop_stack(stack_a));
	write(1, "pb\n", 3);
}

void	ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb\n", 3);
}
