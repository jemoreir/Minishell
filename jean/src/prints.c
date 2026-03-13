/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:04:29 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/12 09:04:29 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	print_error(int code, t_token *token)
{
	if (code == 2)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		if (!token)
			ft_putstr_fd("newline", 2);
		else
			ft_putstr_fd(token->value, 2);
		ft_putstr_fd("'\n", 2);
	}
	else if (code == 1)
		ft_putstr_fd("minishell: syntax error unclosed quote.\n", 2);
	else if (code == 3)
		ft_putstr_fd("minishell: malloc error.\n", 2);
	return (0);
}
