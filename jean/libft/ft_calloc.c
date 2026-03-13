/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:28:54 by jemoreir          #+#    #+#             */
/*   Updated: 2025/04/24 19:36:37 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	if (nmemb > ((size_t) - 1) / size)
		return (NULL);
	ptr = malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, (nmemb * size));
	return (ptr);
}
// int main ()
// {
// 	char *ptr = ft_calloc(5, 2147483647);
// 	char *ptr1 = calloc(5, 2147483647);

// 	if (ptr)
// 		printf("sucesso\n");
// 	else
// 		printf("Erro\n");
// 	if (ptr1)
// 		printf("Sucesso padrao\n");
// 	else
// 		printf("Erro padrao\n");
// }