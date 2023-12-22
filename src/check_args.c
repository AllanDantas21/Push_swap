#include "../includes/push_swap.h"

void    ft_error(char *msg)
{
    ft_putendl_fd(msg, 1);
    exit(0);

}

void	*ft_free(char **mat)
{
	int	i;

	i = 0;
	while (i > 0)
		free(mat[i--]);
	free(mat);
	return (NULL);
}

static int	has_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int has_num(char *num)
{
    int i;

    i = 0;
    if (num[0] == '-')
        i++;
    while(num[i])
    {
        if (!ft_isdigit(num[i]))
            return(0);
        i++;
    }
    return (1);
}

void check_args(char **argv, int  argc)
{
    int     i;
    long    tmp;
    char    **args;

    i = 0;
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        i = 1;
        args = argv;
    }
    while (args[i])
    {
            tmp = ft_atoi(args[i]);
            if (!has_num(args[i]))
                ft_error("Error");
            if (has_duplicate(tmp, args, i))
                ft_error("Error");
            if (tmp < -2147483648 || tmp > 2147483647)
                ft_error("Error");
            i++;
    }
    if (argc == 2)
        ft_free(args);
}