/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:59:19 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:55:25 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_position(t_stack *stack, int val)
{
	t_list	*tmp;
	int		pos;

	tmp = stack->top;
	pos = 0;
	while (tmp && tmp->data != val)
	{
		pos++;
		tmp = tmp->next;
	}
	if (!tmp)
		return (-1);
	return (pos);
}

int	get_target(t_stack *a, int b_val)
{
	t_list	*tmp;
	int		target;
	int		min;

	tmp = a->top;
	target = INT_MAX;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data > b_val && tmp->data < target)
			target = tmp->data;
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	if (target == INT_MAX)
		return (min);
	return (target);
}

int	get_cost(t_stack *a, t_stack *b, int b_val)
{
	int	pos_a;
	int	pos_b;
	int	cost_a;
	int	cost_b;

	pos_b = get_position(b, b_val);
	pos_a = get_position(a, get_target(a, b_val));
	if (pos_b < 0 || pos_a < 0)
		return (INT_MAX);
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

void	ft_assign_index(t_stack *a)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		index;

	tmp = a->top;
	while (tmp)
	{
		index = 0;
		tmp2 = a->top;
		while (tmp2)
		{
			if (tmp2->data < tmp->data)
				index++;
			tmp2 = tmp2->next;
		}
		tmp->index = index;
		tmp = tmp->next;
	}
}
