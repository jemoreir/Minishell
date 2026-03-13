/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:45:53 by jemoreir          #+#    #+#             */
/*   Updated: 2025/10/09 19:47:23 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*teste;

	teste = malloc(sizeof(t_list));
	if (!teste)
		return (NULL);
	teste->next = NULL;
	teste->content = content;
	return (teste);
}
