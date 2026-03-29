/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:42:57 by younux            #+#    #+#             */
/*   Updated: 2026/03/29 23:54:59 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_split(char **split, int i)
{
	int	j;

	j = i + 1;
	while (split[j])
	{
		if (ft_atoi(split[i]) == ft_atoi(split[j++]))
		{
			ft_free_split(split);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

void	ft_validate_split(char *str)
{
	char	**split;
	int		i;

	split = ft_split(str, ' ');
	if (!split || !split[0])
		exit_msg(split);
	i = 0;
	while (split[i])
	{
		if (!ft_number(split[i]) || ft_is_overflow(split[i]))
			exit_msg(split);
		ft_check_split(split, i);
		i++;
	}
	ft_free_split(split);
}

char	**split_arg(char *arg)
{
	char	**res;

	res = ft_split(arg, ' ');
	if (!res)
		error_msg();
	return (res);
}

void	validate_arg(char *arg)
{
	if (has_space(arg))
		ft_validate_split(arg);
	else if (!ft_number(arg) || ft_is_overflow(arg))
		error_msg();
}

void	ft_jma3_o_twi(int argc, char **argv)
{
	int	i;

	if (ft_double(argv, argc))
		error_msg();
	i = 1;
	while (i < argc)
		validate_arg(argv[i++]);
}
