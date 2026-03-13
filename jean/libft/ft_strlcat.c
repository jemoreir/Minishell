/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:00:02 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/07 19:25:44 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = len_dest;
	c = 0;
	if (size <= len_dest)
		return (len_src + size);
	while (src[c] != '\0' && i < size - 1)
	{
		dst[i] = src[c];
		i++;
		c++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
/*int main ()
{
	char src[] = "0";
	char dest[10] = "345";
	char src1[] = "0";
	char dest1[10] = "345";

	printf("my strlcat -> %zu\n", ft_strlcat(dest, src, 6));
	printf("strlcat -> %zu\n", strlcat(dest1, src1, 6));
	printf("%s\n", dest);
	printf("%s\n", dest1);
}*/