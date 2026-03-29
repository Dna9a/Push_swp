/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:59:16 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:55:22 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_best(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	int		best_val;
	int		best_cost;

	if (!b->top)
		return (0);
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
	if (!b->top)
		return ;
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
	if (!a->top)
		return ;
	while (a->top->data != val)
	{
		if (get_position(a, val) <= a->size / 2)
			ra(a);
		else
			rra(a);
	}
}

void	do_combined_rotations(t_stack *a, t_stack *b, int best_val, int target)
{
	int	pos_a;
	int	pos_b;

	if (!a->top || !b->top)
		return ;
	pos_b = get_position(b, best_val);
	pos_a = get_position(a, target);
	while (b->top->data != best_val && a->top->data != target)
	{
		if (pos_b <= b->size / 2 && pos_a <= a->size / 2)
			rr(a, b);
		else if (pos_b > b->size / 2 && pos_a > a->size / 2)
			rrr(a, b);
		else
			break ;
		pos_b = get_position(b, best_val);
		pos_a = get_position(a, target);
	}
}

void	insert_best(t_stack *a, t_stack *b)
{
	int	best_val;
	int	target;

	best_val = find_best(a, b);
	target = get_target(a, best_val);
	do_combined_rotations(a, b, best_val, target);
	bring_to_top_b(b, best_val);
	bring_to_top_a(a, target);
	pa(a, b);
}
