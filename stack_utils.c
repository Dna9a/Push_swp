/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 23:54:22 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:54:25 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->top = NULL;
	stack->size = 0;
}

t_list	*ft_lstnew(int data)
{
	t_list	*nlist;

	nlist = malloc(sizeof(t_list));
	if (nlist == NULL)
		return (NULL);
	nlist->data = data;
	nlist->index = 0;
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

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	value = tmp->data;
	stack->top = tmp->next;
	free(tmp);
	stack->size--;
	return (value);
}

void	ft_free_stack(t_stack *stack)
{
	t_list	*tmp;
	t_list	*next;

	tmp = stack->top;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	stack->top = NULL;
	stack->size = 0;
}
