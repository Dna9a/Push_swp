/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 22:58:51 by yoabied           #+#    #+#             */
/*   Updated: 2026/03/29 23:55:06 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	skip_blanks(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

long	get_overflow(long s, unsigned long r)
{
	if (s == 1 && r > LONG_MAX)
		return (LONG_MAX);
	if (s == -1 && r > (unsigned long)LONG_MAX + 1)
		return (LONG_MIN);
	return (0);
}

long	ft_atol(const char *str)
{
	long			s;
	long			overflow;
	unsigned long	r;
	size_t			i;

	s = 1;
	r = 0;
	i = skip_blanks(str);
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
		overflow = get_overflow(s, r);
		if (overflow)
			return (overflow);
	}
	return ((long)(r * s));
}

int	ft_is_overflow(char *str)
{
	long	n;

	n = ft_atol(str);
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

int	has_space(char *str)
{
	while (*str)
		if (*(str++) == ' ')
			return (1);
	return (0);
}
