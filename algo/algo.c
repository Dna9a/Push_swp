#include "../push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else
		sort_large(a, b);
}

void	sort_large(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size > 0)
		insert_best(a, b);
	rotate_to_min(a);
}

void	rotate_to_min(t_stack *a)
{
	t_list	*tmp;
	int		min;

	tmp = a->top;
	min = a->top->data;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	while (a->top->data != min)
	{
		if (min_is_in_top_half(a, min))
			ra(a);
		else
			rra(a);
	}
}

int	min_is_in_top_half(t_stack *a, int min)
{
	t_list	*tmp;
	int		pos;

	tmp = a->top;
	pos = 0;
	while (tmp->data != min)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos <= a->size / 2);
}

int	get_target(t_stack *a, int b_val)
{
	t_list *tmp;
	int target;
	int best_diff;

	tmp = a->top;
	target = INT_MAX;
	best_diff = INT_MAX;
	while (tmp)
	{
		if (tmp->data > b_val && tmp->data - b_val < best_diff)
		{
			best_diff = tmp->data - b_val;
			target = tmp->data;
		}
		tmp = tmp->next;
	}
	if (target == INT_MAX)
	{
		tmp = a->top;
		while (tmp)
		{
			if (tmp->data < target || target == INT_MAX)
				target = tmp->data;
			tmp = tmp->next;
		}
	}
	return (target);
}
