/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 12:44:18 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/26 14:38:03 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n == -2147483648)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else
		{
			if (n < 0)
			{
				ft_putchar_fd('-', fd);
				n = -n;
			}
			if (n > 9)
				ft_putnbr_fd((n / 10), fd);
			ft_putchar_fd((n % 10 + 48), fd);
		}
	}
}
// int main ()
// {
// 	int teste = open("putnbr.txt", O_WRONLY | O_CREAT, 0644);
// 	ft_putnbr_fd(545, teste);
// 	close(teste);
// }