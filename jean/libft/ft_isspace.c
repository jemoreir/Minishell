#include "libft.h"

int	ft_isspace(int c)
{
	return (c == 32 || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

/*int main()
{
	int c = 'a';

	printf("%i\n", ft_isspace(c));
	printf("%i\n", isspace(c));
}*/