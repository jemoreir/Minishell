#include "libft.h"

int	ft_is_op(int c)
{
	return (ft_is_redir(c) || ft_ispipe(c));
}

/* int main()
{
    int a = 'a';

    printf("%i\n", ft_is_op(a));
} */