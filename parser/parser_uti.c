/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_uti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 11:48:47 by younux            #+#    #+#             */
/*   Updated: 2026/03/29 23:55:09 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	exit_msg(char **split)
{
	if (split)
		ft_free_split(split);
	write(2, "Error\n", 6);
	exit(1);
}

void	error_msg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**safe_split(char *arg)
{
	char	**res;

	res = ft_split(arg, ' ');
	if (!res)
		exit_msg(NULL);
	return (res);
}

int	ft_cmp_split_args(char **si, char *argj)
{
	char	**sj;
	int		k;
	int		l;

	sj = safe_split(argj);
	k = 0;
	while (si[k])
	{
		l = 0;
		while (sj[l])
		{
			if (ft_atoi(si[k]) == ft_atoi(sj[l]))
				return (ft_free_split(sj), 1);
			l++;
		}
		k++;
	}
	ft_free_split(sj);
	return (0);
}
