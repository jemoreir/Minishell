/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:10:35 by jemoreir          #+#    #+#             */
/*   Updated: 2026/03/11 20:09:13 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	h_redir_in(t_token **tks, t_cmd *cmd)
{
	t_token	*new;

	free(cmd->infile);
	cmd->infile = ft_strdup((*tks)->next->value);
	if (!cmd->infile)
		return (1);
	new = new_token(T_REDIR_IN, ft_strdup(cmd->infile));
	token_add_back(&cmd->redirs, new);
	(*tks) = (*tks)->next->next;
	return (0);
}

int	h_redir_out_append(t_token **tks, t_cmd *cmd)
{
	t_token	*new;

	free(cmd->outfile);
	cmd->outfile = ft_strdup((*tks)->next->value);
	if (!cmd->outfile)
		return (1);
	if ((*tks)->type == T_REDIR_APPEND)
	{
		cmd->out_append = 1;
		new = new_token(T_REDIR_APPEND, ft_strdup(cmd->outfile));
		token_add_back(&cmd->redirs, new);
	}
	if ((*tks)->type == T_REDIR_OUT)
	{
		cmd->out_append = 0;
		new = new_token(T_REDIR_OUT, ft_strdup(cmd->outfile));
		token_add_back(&cmd->redirs, new);
	}
	(*tks) = (*tks)->next->next;
	return (0);
}

int	h_redir_heredoc(t_token **tks, t_cmd *cmd)
{
	t_token	*new;
	int		qt;
	int		i;

	i = 0;
	free(cmd->limiter);
	cmd->limiter = ft_strdup((*tks)->next->value);
	if (!cmd->limiter)
		return (1);
	qt = ft_is_quote(cmd->limiter[i]);
	if (qt == 1)
		cmd->limiter = ft_strtrim(cmd->limiter, "'");
	else if (qt == 2)
		cmd->limiter = ft_strtrim(cmd->limiter, "\"");
	new = new_token(T_REDIR_HEREDOC, ft_strdup(cmd->limiter));
	token_add_back(&cmd->redirs, new);
	(*tks) = (*tks)->next->next;
	return (0);
}

int	parse_redir(t_token **tks, t_cmd *cmd)
{
	if (!(*tks)->next)
		return (2);
	if ((*tks)->next->type != T_WORD)
		return (1);
	if ((*tks)->type == T_REDIR_IN)
		return (h_redir_in(tks, cmd));
	else if ((*tks)->type == T_REDIR_OUT || (*tks)->type == T_REDIR_APPEND)
		return (h_redir_out_append(tks, cmd));
	else if ((*tks)->type == T_REDIR_HEREDOC)
		return (h_redir_heredoc(tks, cmd));
	return (1);
}
int	h_var(char *var, t_data *data, int *i, char **res)
{
	char	*name;
	char	*tmp;
	int		err;
	
	name = NULL;
	err = init_name_var(var, i, &name);
	if (err == 3)
		return (err);
	if (err == 1)
	{
		if (append_join(res, "$"))
			return (free_word_err(3, name));
	}
	else
	{
		tmp = get_env_value(name, data->cpy_env);
		if (tmp)
		{
			if (append_join(res, tmp))
				return (free_word_err(3, name));
		}
	}
	free(name);
	return (0);
}

int	h_var_last_exit(t_data *data, char **res, int *i)
{
	char	*tmp;
	int		err;
	
	tmp = NULL;
	tmp = ft_itoa(data->l_exit);
	if (!tmp)
		return (3);
	err = append_join(res, tmp);
	if (err)
		return (free_word_err(3, tmp));
	free(tmp);
	(*i)++;
	return (0);
}

void	handler_signal(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}
