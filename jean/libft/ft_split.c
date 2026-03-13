#include "libft.h"

static size_t	count_word(char const *str, char d)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != d && (i == 0 || str[i - 1] == d))
			count++;
		i++;
	}
	return (count);
}

void	*free_array(char **s)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	return (NULL);
}

static char	*words(char const *str, char d)
{
	size_t	i;
	size_t	m;
	size_t	t;
	char	*res;

	i = 0;
	t = 0;
	m = 0;
	while (str[i] && str[i] != d)
		i++;
	res = malloc(sizeof (char) * (i + 1));
	if (!res)
		return (NULL);
	while (t < i)
		res[t++] = str[m++];
	res[t] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	p;
	char	**res;

	i = 0;
	p = count_word(s, c);
	if (!s)
		return (NULL);
	res = malloc(sizeof (char *) * (p + 1));
	if (!res)
		return (NULL);
	while (i < p)
	{
		while (*s == c)
			s++;
		res[i] = words(s, c);
		if (!res[i])
			return (free_array(res));
		i++;
		while (*s && *s != c)
			s++;
	}
	res[i] = NULL;
	return (res);
}

// static void	print_split(char **split_result)
// {
// 	int i = 0;
// 	while (split_result[i])
// 	{
// 		printf("Palavra %d: %s\n", i, split_result[i]);
// 		i++;
// 	}
// }

// int main ()
// {
// 	char a[] = "Ola Jean tudo bem?";
// 	print_split(ft_split(a, ' '));
// }