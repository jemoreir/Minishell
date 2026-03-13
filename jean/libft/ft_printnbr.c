/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:51:35 by jemoreir          #+#    #+#             */
/*   Updated: 2025/10/16 17:05:30 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int n)
{
	int		count;
	long	n2;

	n2 = n;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n2 = -n2;
	}
	if (n2 > 9)
		count += ft_printnbr(n2 / 10);
	count += ft_putchar((n2 % 10) + 48);
	return (count);
}
