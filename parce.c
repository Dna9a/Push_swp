#include "push_swap.h"

/*
The parser needs to check 3 things:
✅ Only digits (and maybe a - or + sign at the start)
✅ No duplicates
✅ No integer overflow (number fits in an int)
*/

int	ft_is_valid_number(char *str)
{
	int i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
