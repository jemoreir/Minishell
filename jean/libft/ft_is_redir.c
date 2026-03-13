#include "libft.h"

int	ft_is_redir(int c)
{
	return (c == '<' || c == '>');
}

/* int main()
{
    int a = '<';

    printf("%i\n", ft_is_redir(a));
} */