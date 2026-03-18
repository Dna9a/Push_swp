/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:59:14 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/18 22:59:15 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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