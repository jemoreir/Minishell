/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:33:09 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/06 20:46:16 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*int main(void)
{
	char str[] = "123456789";
	char st[] = "000000000";

	ft_bzero(str, 5);
	bzero(st, 5);
	for(int i = 0; i < 9; i++)
	{
		printf ("%c\n", str[i]);
	}
	for (int b = 0; b < 9; b++)
	{
		printf ("%c\n", st[b]);
	}
}*/