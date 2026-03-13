#include "libft.h"

size_t	ft_len(const char *buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	return (i);
}

void	*ft_memcpy_get(void *dest, const void *src, size_t n)
{
	unsigned const char	*o;
	unsigned char		*d;
	size_t				i;

	i = 0;
	d = (unsigned char *) dest;
	o = (unsigned const char *) src;
	while (i < n)
	{
		d[i] = o[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin_get(char *line, char *buffer)
{
	char	*res;

	if (!line)
	{
		line = malloc(sizeof (char) * 1);
		line[0] = '\0';
	}
	if (!line && !buffer)
		return (NULL);
	res = malloc(sizeof (char) * (ft_len(line) + ft_len(buffer)) + 1);
	if (!res)
		return (NULL);
	ft_memcpy_get(res, line, ft_len(line));
	ft_memcpy_get(res + ft_len(line), buffer, ft_len(buffer));
	res[ft_len(line) + ft_len(buffer)] = '\0';
	free(line);
	free(buffer);
	return (res);
}

char	*ft_substr_get(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	t;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_len(s))
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub_len = 0;
	while (sub_len < len && s[start + sub_len])
		sub_len++;
	sub = malloc(sizeof (char) * sub_len + 1);
	if (!sub)
		return (NULL);
	t = 0;
	while (t < sub_len)
		sub[t++] = s[start++];
	sub[t] = '\0';
	return (sub);
}

char	*ft_check_error_get(int n, char *nline, char *buffer)
{
	buffer[0] = '\0';
	if (n == -1 || !nline || *nline == '\0')
	{
		free(nline);
		return (NULL);
	}
	if (n == 0)
		return (nline);
	return (NULL);
}
