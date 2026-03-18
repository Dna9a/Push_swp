/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:42 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/18 22:58:45 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int data)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist == NULL)
		return (NULL);
	nlist->data = data;
	nlist->next = NULL;
	return (nlist);
}

void	ft_push_stack(t_stack *stack, int value)
{
	t_list	*new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		return ;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

int	ft_pop_stack(t_stack *stack)
{
	int		value;
	t_list	*tmp;

	tmp = stack->top;
	value = tmp->data;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (value);
}
