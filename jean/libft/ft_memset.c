/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:14:50 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/16 18:45:02 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*b;
	size_t			i;

	b = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		b[i] = c;
		i++;
	}
	return (s);
}
/*int main ()
{
	char str[20] = "Que dificuldade.";
	printf("antes da funcao: %s\n", str);
	ft_memset(str, '0', 5);
	printf("Depois do meu memset: %s\n", str);
	memset(str, '1', 5);
	printf("Memset original: %s\n", str);
}*/