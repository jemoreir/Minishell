/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:00:18 by jemoreir          #+#    #+#             */
/*   Updated: 2025/05/07 19:32:09 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		t = 0;
		while (i + t < len && big[i + t] == little[t])
		{
			t++;
			if (little[t] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
// int main ()
// {
// 	char big[] = "Ola Jean";
// 	char little[] = "Ole";

// 	printf("%s\n", ft_strnstr(big, little, 4));
// 	printf("%s\n", strnstr(big, little, 4));
// }