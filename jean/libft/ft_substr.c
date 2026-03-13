/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:40:48 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/25 15:32:34 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	sub_len;
	size_t	t;
	char	*sub;

	if (!s)
		return (NULL);
	if (start > (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	sub_len = 0;
	while (sub_len < len && s[start + sub_len])
		sub_len++;
	sub = malloc(sizeof (char) * sub_len + 1);
	if (!sub)
		return (NULL);
	t = 0;
	while (t < sub_len)
	{
		sub[t] = s[start + t];
		t++;
	}
	sub[t] = '\0';
	return (sub);
}
// int main ()
// {
// 	printf("%s\n", ft_substr("jean", 1, 1));
// }