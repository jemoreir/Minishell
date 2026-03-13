/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:02:15 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/26 15:21:50 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd >= 0)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}
// int main ()
// {
// 	int a = open("teste1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	ft_putendl_fd("Ola me chamo Jean", a);
// 	close(a);
// }