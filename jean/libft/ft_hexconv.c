/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 20:27:36 by jemoreir          #+#    #+#             */
/*   Updated: 2025/10/16 17:06:10 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexconv(unsigned long ptr, char a)
{
	char	*hex;
	char	*hexb;
	int		i;

	hex = "0123456789abcdef";
	hexb = "0123456789ABCDEF";
	i = 0;
	if (a == 'X')
	{
		if (ptr >= 16)
			i += ft_hexconv (ptr / 16, a);
		i += ft_putchar(hexb[ptr % 16]);
		return (i);
	}
	else
	{
		if (ptr >= 16)
			i += ft_hexconv (ptr / 16, a);
		i += ft_putchar(hex[ptr % 16]);
		return (i);
	}
}
