/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oplen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:55:48 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/23 16:02:52 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_oplen(char *op, int i)
{
	int	t;

	t = 0;
	while (op[t])
		t++;
	return (i + t);
}

/* int main()
{
	char *op = "|";
	int i = 0;
	printf("%i\n", ft_oplen(op, i));
} */
