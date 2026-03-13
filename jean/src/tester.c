/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 13:50:15 by jemoreir          #+#    #+#             */
/*   Updated: 2026/03/11 13:50:15 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

char	*token_type_str(t_token_t token)
{
	if (token == T_PIPE)
		return ("PIPE");
	if (token == T_WORD)
		return ("WORD");
	if (token == T_REDIR_IN)
		return ("REDIR <");
	if (token == T_REDIR_OUT)
		return ("REDIR >");
	if (token == T_REDIR_APPEND)
		return ("REDIR >>");
	if (token == T_REDIR_HEREDOC)
		return ("REDIR <<");
	if (!token)
		return ("Tipo nao existe\n");
	return (NULL);
}

void	*print_tokens(t_token *list)
{
	int	i;

	i = 0;
	if (!list)
	{
		printf("Tokens nao existe\n");
		return (NULL);
	}
	while (list)
	{
		printf("token[%i] = %s[%s]\n", i, list->value,
			token_type_str(list->type));
		list = list->next;
		i++;
	}
	return (NULL);
}

void	print_cmd(t_cmd *cmds)
{
	int		cmd;
	t_token	*tmp;

	cmd = 1;
	if (!cmds)
		return ;
	while (cmds)
	{
		printf("--- // ---\n");
		printf("indice cmd: %i\nac: %i\n", cmd, cmds->ac);
		if (cmds->av)
		{
			for (int t = 0; t < cmds->ac; t++)
				printf("av[%i]: [%s] \n", t,
					cmds->av[t] ? cmds->av[t] : "(null)");
		}
		else
			printf("av: (null)\n");
		if (cmds->redirs)
		{
			tmp = cmds->redirs;
			while (cmds->redirs)
			{
				printf("target: [%s] token: [%s]\n",
					cmds->redirs->value ? cmds->redirs->value : "(null)",
					token_type_str(cmds->redirs->type) ?
					token_type_str(cmds->redirs->type) : "(null)");
				cmds->redirs = cmds->redirs->next;
			}
			cmds->redirs = tmp;
		}
		printf("infile: %s\noutfile: %s\nout_append: %i\nlimiter: %s\n",
			cmds->infile ? cmds->infile : "(null)",
			cmds->outfile ? cmds->outfile : "(null)", cmds->out_append,
			cmds->limiter ? cmds->limiter : "(null)");
		printf("--- // ---\n");
		cmd++;
		cmds = cmds->next;
	}
}
