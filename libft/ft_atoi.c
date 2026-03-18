/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:47:56 by yoabied           #+#    #+#             */
/*   Updated: 2025/11/03 20:53:44 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	long			s;
	unsigned long	r;
	size_t			i;

	s = 1;
	r = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		r = r * 10 + (str[i] - '0');
		i++;
		if (s == 1 && r > LONG_MAX)
			return (-1);
		if (s == -1 && r > (unsigned long)LONG_MAX + 1)
			return (0);
	}
	return ((int)(r * s));
}
