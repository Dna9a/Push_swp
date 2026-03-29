/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_libft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoabied <yoabied@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:53 by younux            #+#    #+#             */
/*   Updated: 2026/03/29 23:55:33 by yoabied          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_fillres(char **res, int res_len, const char *str, char sp)
{
	int	i;
	int	wrdlen;

	i = 0;
	while (i < res_len)
	{
		while (*str && *str == sp)
			str++;
		wrdlen = 0;
		while (*(str + wrdlen) && *(str + wrdlen) != sp)
			wrdlen++;
		if (!fill_word(&res[i], str, wrdlen))
			return (0);
		str += wrdlen;
		i++;
	}
	res[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		res_len;

	if (!s)
		return (NULL);
	res_len = ft_count_word(s, c);
	res = malloc(sizeof(char *) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	if (!ft_fillres(res, res_len, s, c))
	{
		while (res_len > 0)
			free(res[--res_len]);
		free(res);
		return (NULL);
	}
	return (res);
}
