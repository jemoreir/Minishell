/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:04:23 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/12 09:04:23 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_cmd	*create_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->av = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->ac = 0;
	cmd->out_append = 0;
	cmd->next = NULL;
	cmd->limiter = NULL;
	cmd->redirs = NULL;
	return (cmd);
}

char	**push_arg(char **av, int ac, t_token *token)
{
	char	**n_av;
	int		n_size;
	int		i;

	n_size = ac + 2;
	n_av = malloc(sizeof(char *) * (n_size));
	if (!n_av)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		n_av[i] = av[i];
		i++;
	}
	n_av[ac] = ft_strdup(token->value);
	if (!n_av[ac])
	{
		free(n_av);
		return (NULL);
	}
	n_av[ac + 1] = NULL;
	free(av);
	return (n_av);
}

t_cmd	*put_t_word(t_cmd *cmd, t_token **token, t_data *d)
{
	char	**tmp;
	int		code;

	code = 0;
	while (*token && (*token)->type != T_PIPE)
	{
		if ((*token)->type == T_WORD)
		{
			tmp = push_arg(cmd->av, cmd->ac, *token);
			if (!tmp)
				return (free_cmd(cmd));
			cmd->av = tmp;
			cmd->ac++;
			*token = (*token)->next;
		}
		else if (!is_redir(*token))
			return (free_cmd(cmd));
		else
			code = parse_redir(token, cmd);
		if (code == 2)
			return (error_exit(cmd, T_FREE_CMD, 2, NULL, &d->l_exit));
		else if (code == 1)
			return (error_exit(cmd, T_FREE_CMD, 2, (*token)->next, &d->l_exit));
	}
	return (cmd);
}

static t_cmd	*parse_simple(t_token **tokens, t_data *d)
{
	t_cmd	*cmd;

	cmd = create_cmd();
	if (!cmd)
		return (NULL);
	return (put_t_word(cmd, tokens, d));
}

t_cmd	*parse_pipeline(t_token **tokens, t_data *d)
{
	t_cmd	*cmd;

	if (!tokens || !*tokens)
		return (NULL);
	if ((*tokens)->type == T_PIPE)
		return (error_exit(NULL, T_FREE_TOKENS, 2, *tokens, &d->l_exit));
	cmd = parse_simple(tokens, d);
	if (!cmd)
		return (NULL);
	if (*tokens && (*tokens)->type == T_PIPE)
	{
		*tokens = (*tokens)->next;
		if (!*tokens)
			return (error_exit(cmd, T_FREE_CMD, 2, NULL, &d->l_exit));
		else if ((*tokens)->type == T_PIPE)
			return (error_exit(cmd, T_FREE_CMD, 2, *tokens, &d->l_exit));
		cmd->next = parse_pipeline(tokens, d);
		if (!cmd->next)
			return (error_exit(cmd, T_FREE_CMD, 2, *tokens, &d->l_exit));
	}
	d->l_exit = 0;
	return (cmd);
}

/* int	main(int ac, char **av, char **envp)
{
	t_token	*tokens;
	t_token	*cur;
	t_cmd	*cmd;
	t_data	*data;

	data = init_data();
	if (!data)
		return (3);
	cpy_env(envp, data);

	for (int i = 1; i < ac; i++)
	{
		tokens = lexer(av[i], data);
		cur = tokens;
		cmd = parse_pipeline(&cur, data);
		print_cmd(cmd);
		free_tokens(tokens);
		free_cmd(cmd);
	}
	free_data(data);
} */
