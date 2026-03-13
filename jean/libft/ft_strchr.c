/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:56:27 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/19 13:22:04 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	if (cc == '\0')
	{
		while (s[i])
			i++;
		return ((char *) &s[i]);
	}
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}
/*int main ()
{
	char s[] = "Oi me chamo jean";
	
	printf("%s\n", ft_strchr(s, '\0'));
}*/