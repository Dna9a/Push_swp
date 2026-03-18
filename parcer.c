#include "push_swap.h"

int	ft_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (0);
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

int	ft_double(char **argv, int argc)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static long	ft_atol(const char *str)
{
	long			s;
	unsigned long	r;
	size_t			i;

	s = 1;
	r = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (r > ((unsigned long)INT_MAX + 1) / 10)
		{
			if (s == 1)
				return ((long)INT_MAX + 1);
			return ((long)INT_MIN - 1);
		}
		r = r * 10 + (str[i] - '0');
		i++;
		if (s == 1 && r > (unsigned long)INT_MAX)
			return ((long)INT_MAX + 1);
		if (s == -1 && r > (unsigned long)INT_MAX + 1)
			return ((long)INT_MIN - 1);
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

void	ft_jma3_o_twi(int argc, char **argv)
{
	int i;

	i = 1;
	if (ft_double(argv, argc))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (i < argc)
	{
		if (!ft_number(argv[i]) || ft_is_overflow(argv[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}