/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:59 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/18 22:59:00 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp;
}

void	ft_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	last = stack->top;
	while (last->next)
		last = last->next;
	stack->top = tmp->next;
	last->next = tmp;
	tmp->next = NULL;
}

void	ft_reverse_rotate(t_stack *stack)
{
	t_list	*tmp;
	t_list	*last;

	if (stack->size < 2)
		return ;
	tmp = stack->top;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = stack->top;
	stack->top = last;
}
