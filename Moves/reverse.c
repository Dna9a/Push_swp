#include "../push_swap.h"

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_stack *stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}