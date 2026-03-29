/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:59:14 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:55:28 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_is_in_top_half(t_stack *a, int min)
{
	int	pos;

	pos = get_position(a, min);
	if (pos < 0)
		return (1);
	return (pos <= a->size / 2);
}

void	rotate_to_min(t_stack *a)
{
	t_list	*tmp;
	int		min;

	if (!a || a->size < 2 || !a->top)
		return ;
	tmp = a->top;
	min = tmp->data;
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

void	push_to_b_smart(t_stack *a, t_stack *b)
{
	int	chunk;
	int	pushed;
	int	median;

	chunk = a->size / 5;
	pushed = 0;
	median = chunk;
	while (a->size > 3)
	{
		if (a->top->index <= median)
		{
			pb(a, b);
			if (++pushed >= chunk)
			{
				median += chunk;
				pushed = 0;
			}
		}
		else
			ra(a);
	}
}

void	sort_large(t_stack *a, t_stack *b)
{
	ft_assign_index(a);
	push_to_b_smart(a, b);
	sort_three(a);
	while (b->size > 0)
		insert_best(a, b);
	rotate_to_min(a);
}
