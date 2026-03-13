/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 11:28:10 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/12 12:19:04 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*int main()
{
	int a = '9';
	int b = 'a';

	printf("Resultado: %d\n", ft_isdigit(b));
	printf("%d\n", isdigit(a));
}*/