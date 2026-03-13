/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 17:56:35 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/26 19:24:06 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static char	ft_function(unsigned int n, char c)
// {
// 	(void) n;
// 	return (c - 32);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (ft_strdup("0"));
	str = malloc(sizeof (char) * ft_strlen(s) +1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// int main ()
// {
// 	char	s[] = "ola";

// 	printf("%s\n", ft_strmapi(s, ft_function));
// }