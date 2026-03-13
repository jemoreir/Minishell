/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:32:38 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/06 20:24:31 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	c;

	c = 0;
	if (n < 0)
		c++;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	n2;
	int		len;

	n2 = n;
	if (n2 == 0)
		return (ft_strdup("0"));
	len = ft_count(n2);
	res = malloc(sizeof (char) * (len + 1));
	if (!res)
		return (NULL);
	if (n2 < 0)
	{
		n2 = -n2;
		res[0] = '-';
	}
	res[len] = '\0';
	while (n2 != 0)
	{
		res[--len] = (n2 % 10) + '0';
		n2 /= 10;
	}
	return (res);
}
// int main ()
// {
// 	printf("%s\n", ft_itoa(1234));
// }