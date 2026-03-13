/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:22:43 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/29 19:58:07 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	inicio;
	size_t	fim;
	size_t	new;
	char	*nstr;

	if (!s1 || !set)
		return (NULL);
	inicio = 0;
	while (s1[inicio] && is_in(s1[inicio], set))
		inicio++;
	fim = ft_strlen(s1);
	while (fim > inicio && is_in(s1[fim - 1], set))
		fim--;
	nstr = malloc (sizeof (char) * (fim - inicio) + 1);
	if (!nstr)
		return (NULL);
	new = 0;
	while (inicio < fim)
		nstr[new++] = s1[inicio++];
	nstr[new] = '\0';
	return (nstr);
}
// int main ()
// {
// 	char s1[] = "--Mundo--";
// 	char set[] = "-";
// 	printf("%s\n", ft_strtrim(s1, set));
// }