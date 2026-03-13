/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:43:02 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/05 20:53:47 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/*int main ()
{
	char src[] = "12345";
	char dest[] = "";
	char src1[] = "abcde";
	char dest1[] = "";

	printf("Meu strlcpy = %zu\n", ft_strlcpy(dest, src, 4));
	printf("%s\n", dest);
	
	printf("strlcpy padrao = %zu\n", strlcpy(dest1, src1, 4));
	printf("%s\n", dest1);
}*/