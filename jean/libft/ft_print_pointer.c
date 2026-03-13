/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:17:13 by jemoreir          #+#    #+#             */
/*   Updated: 2025/10/16 17:05:05 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_pointer(unsigned long ptr)
{
	int	i;

	if (!ptr)
		return (ft_putstr("(nil)"));
	write (1, "0x", 2);
	i = 2;
	ft_hexconv(ptr, 'a');
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}
