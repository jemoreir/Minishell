/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:42:34 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/26 14:59:13 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd >= 0)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i++], 1);
		}
	}
}
// int main ()
// {
// 	int t = open("test", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	ft_putstr_fd("Ola Mundo", t);
// 	close(t);
// }