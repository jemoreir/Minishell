/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:03:10 by jemoreir          #+#    #+#             */
/*   Updated: 2025/07/09 19:30:11 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*o;
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
// int main()
// {
// 	char origem[] = "123456";
// 	char destino[] = "a";

// 	printf("%s\n", destino);
// 	ft_memcpy(NULL, NULL, 1);
// 	memcpy(NULL, NULL, 3);
// 	printf("%s\n", destino);
// }