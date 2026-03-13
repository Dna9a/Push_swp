#include "push_swap.h"

t_stack start_stack(int size)
{
	t_stack stack;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->arr = malloc(sizeof(int) * size);
	if (!stack->arr)
		return (NULL);
	stack->top = -1;
	stack->size = size;
	return (stack);
}

# i need to free twice ig.