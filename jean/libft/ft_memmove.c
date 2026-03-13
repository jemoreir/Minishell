/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:43:22 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/07 19:38:18 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_char;
	unsigned char	*src_char;
	size_t			i;

	i = n;
	dest_char = (unsigned char *) dest;
	src_char = (unsigned char *) src;
	if (dest_char > src_char)
	{
		while (i > 0)
		{
			dest_char[i - 1] = src_char[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dest_char, src_char, n);
	return (dest);
}
// int main()
// {
// 	char src[20] = "1234567890";
// 	int a;
// 	(void) a;
// 	char teste[20] = "1234567890";

// 	memmove(&src[4], &src[6], 1);
// 	printf("%s\n", src);
// 	ft_memmove(&teste[4], &teste[6], 1);
// 	printf("%s\n", teste);
// }