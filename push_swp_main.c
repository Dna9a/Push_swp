#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	i = ac - 1;
	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	ft_jma3_o_twi(ac, av);
	while (i >= 1)
	{
		ft_push_stack(&stack_a, ft_atoi(av[i]));
		i--;
	}
	push_swap(&stack_a, &stack_b);
	return (0);
}
