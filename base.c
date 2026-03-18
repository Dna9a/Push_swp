/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:53 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/18 22:58:54 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	top = a->top->data;
	mid = a->top->next->data;
	bot = a->top->next->next->data;
	if (is_sorted(a))
		return ;
	if (top > mid && top > bot)
		ra(a);
	else if (bot > mid && bot > top)
		rra(a);
	if (a->top->data > a->top->next->data)
		sa(a);
}
