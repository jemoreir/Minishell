#include "libft.h"

int	ft_is_word_char(int c)
{
	return (!ft_isspace(c) && !ft_ispipe(c));
}

/*int main()
{
    int a = '\0';

    printf("%i\n", ft_is_word_char(a));
}*/