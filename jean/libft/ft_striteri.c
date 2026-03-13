/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:29:48 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/26 19:56:04 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static void	ft_teste(unsigned int n, char *s)
// {
// 	n = 0;
// 	s[n] += 32;
// 	return;
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// int main ()
// {
// 	char s[] = "";
// 	ft_striteri(s, ft_teste);
// 	printf("%s\n", s);
// }