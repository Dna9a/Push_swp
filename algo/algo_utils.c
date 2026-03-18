#include "push_swap.h"

int	get_position(t_stack *stack, int val)
{
	t_list	*tmp;
	int		pos;

	tmp = stack->top;
	pos = 0;
	while (tmp->data != val)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	get_cost(t_stack *a, t_stack *b, int b_val)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_b = get_position(b, b_val);
	pos_a = get_position(a, get_target(a, b_val));
	if (pos_b <= b->size / 2)
		cost_b = pos_b;
	else
		cost_b = b->size - pos_b;
	if (pos_a <= a->size / 2)
		cost_a = pos_a;
	else
		cost_a = a->size - pos_a;
	return (cost_a + cost_b);
}
