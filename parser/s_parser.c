/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:33:38 by younux            #+#    #+#             */
/*   Updated: 2026/03/29 23:54:57 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_double(char **argv, int argc)
{
	int		i;
	int		j;
	char	**si;

	i = 1;
	while (i < argc)
	{
		si = split_arg(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			if (ft_cmp_split_args(si, argv[j++]))
			{
				ft_free_split(si);
				return (1);
			}
		}
		ft_free_split(si);
		i++;
	}
	return (0);
}
