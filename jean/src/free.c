/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:42 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/23 15:37:42 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

void	*free_cmd(t_cmd *cmd)
{
	int		i;
	t_cmd	*next;

	while (cmd)
	{
		i = 0;
		next = cmd->next;
		if (cmd->av)
		{
			while (cmd->av[i])
				free(cmd->av[i++]);
			free(cmd->av);
		}
		if (cmd->redirs)
			free_tokens(cmd->redirs);
		if (cmd->limiter)
			free(cmd->limiter);
		if (cmd->infile)
			free(cmd->infile);
		if (cmd->outfile)
			free(cmd->outfile);
		free(cmd);
		cmd = next;
	}
	return (NULL);
}

void	free_tokens(t_token *tokens)
{
	t_token	*next;

	if (!tokens)
		return ;
	while (tokens)
	{
		next = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = next;
	}
	return ;
}

int	free_word_err(int err, char *word)
{
	if (word)
		free(word);
	return (err);
}

int	join_free(t_token **list, char **word, char *tmp, int *first)
{
	char	*res;

	if (*first)
	{
		(*first) = 0;
		res = ft_strjoin_mini(*word, tmp);
		free(tmp);
		if (!res)
			return (3);
		*word = res;
	}
	else
	{
		if (token_push(list, T_WORD, *word, NULL))
		{
			free(tmp);
			return (3);
		}
		*word = tmp;
	}
	return (0);
}

void	*error_exit(void *ptr, t_free_t ty, int e, t_token *t, int *l_exit)
{
	print_error(e, t);
	if (ty == T_FREE_CMD)
		free_cmd((t_cmd *)ptr);
	else if (ty == T_FREE_TOKENS)
		free_tokens((t_token *)ptr);
	else if (ty == T_FREE_LINE)
		free(ptr);
	if (e == 1 && l_exit)
		*l_exit = 2;
	else
		*l_exit = e;
	return (NULL);
}
