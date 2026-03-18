/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:59:16 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/18 22:59:18 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_best(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		best_val;
	int		best_cost;

	tmp = b->top;
	best_val = b->top->data;
	best_cost = INT_MAX;
	while (tmp)
	{
		if (get_cost(a, b, tmp->data) < best_cost)
		{
			best_cost = get_cost(a, b, tmp->data);
			best_val = tmp->data;
		}
		tmp = tmp->next;
	}
	return (best_val);
}

void	bring_to_top_b(t_stack *b, int val)
{
	while (b->top->data != val)
	{
		if (get_position(b, val) <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}

void	bring_to_top_a(t_stack *a, int val)
{
	while (a->top->data != val)
	{
		if (get_position(a, val) <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	insert_best(t_stack *a, t_stack *b)
{
	int best_val;

	best_val = find_best(a, b);
	bring_to_top_b(b, best_val);
	bring_to_top_a(a, get_target(a, best_val));
	pa(a, b);
}