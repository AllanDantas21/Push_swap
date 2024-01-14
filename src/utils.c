#include "../includes/push_swap.h"

void	ft_error(char *msg, char **args, int argc)
{
	if (argc == 2)
		ft_free((void **)args);
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(0);
}

void	ft_free(void **mat)
{
	size_t	i;

	i = 0;
	while (mat[i])
		free(mat[i++]);
	free(mat);
}

size_t	count_nums(char const *s, char c)
{
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res *= 10;
		res += *nptr++ - '0';
	}
	return ((long)(res * sign));
}

int	invalid_input(char *str)
{
	int	final;

	final = ft_strlen(str) - 1;
	if (str[final] == ' ' &&  (count_nums(str, ' ') > 1))
		return (1);
	return (0);
}