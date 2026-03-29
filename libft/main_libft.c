/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:52:14 by younux            #+#    #+#             */
/*   Updated: 2026/03/29 23:55:30 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	overflow_guard(long s, unsigned long r)
{
	if (s == 1 && r > LONG_MAX)
		return (-1);
	if (s == -1 && r > (unsigned long)LONG_MAX + 1)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long			s;
	unsigned long	r;
	int				guard;

	s = 1;
	r = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		r = r * 10 + (*str - '0');
		guard = overflow_guard(s, r);
		if (guard != 1)
			return (guard);
		str++;
	}
	return ((int)(r * s));
}

int	ft_count_word(const char *s, char c)
{
	size_t	i;
	size_t	ct;

	i = 0;
	ct = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			ct++;
		i++;
	}
	return (ct);
}

int	fill_word(char **slot, const char *str, int len)
{
	int	j;

	*slot = (char *)malloc(sizeof(char) * (len + 1));
	if (!*slot)
		return (0);
	j = 0;
	while (j < len)
	{
		(*slot)[j] = str[j];
		j++;
	}
	(*slot)[j] = '\0';
	return (1);
}
