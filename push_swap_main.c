/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:46 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:54:36 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_split_args(t_stack *a, char **split)
{
	int	j;

	j = 0;
	while (split[j])
		j++;
	while (j > 0)
		ft_push_stack(a, ft_atoi(split[--j]));
}

void	push_arg(t_stack *a, char *arg)
{
	char	**split;

	if (!has_space(arg))
	{
		ft_push_stack(a, ft_atoi(arg));
		return ;
	}
	split = ft_split(arg, ' ');
	if (!split)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	push_split_args(a, split);
	ft_free_split(split);
}

void	fill_stack_from_args(int ac, char **av, t_stack *a)
{
	int	i;

	i = ac - 1;
	while (i >= 1)
	{
		push_arg(a, av[i]);
		i--;
	}
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	ft_jma3_o_twi(ac, av);
	fill_stack_from_args(ac, av, &stack_a);
	push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	return (0);
}
