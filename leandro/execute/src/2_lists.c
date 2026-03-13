/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_lists.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/11 18:38:49 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	list_cmds(t_data *data)
{
	t_cmd	*cmd;
	t_cmd	*lst_cmd;
	
	lst_cmd = NULL;
	while (data->tokens)
	{
		cmd = malloc(sizeof(t_cmd));
		if (!cmd)
			exit_error(data, "malloc cmd", 1);
		init_cmd(cmd);
		split_list(data, cmd);
		link_cmd(data, &lst_cmd, cmd);
	}
}

void	init_cmd(t_cmd *cmd)
{
	cmd->avlist = NULL;
	cmd->redirs = NULL;	
	cmd->argv = NULL;
	cmd->bin = NULL;
	cmd->fdin = -1;
	cmd->fdout = -1;
	cmd->pid = -1;
	cmd->nxt = NULL;	
}

void	split_list(t_data *data, t_cmd *cmd)
{	
	t_token	*lst_argv;
	t_token *lst_redir;

	lst_argv = NULL;
	lst_redir = NULL;	
	while (data->tokens && data->tokens->type != PIPE)
	{
		if (data->tokens->type == WORD)
			link_list(data, &lst_argv, cmd, 'a');
		else	
			link_list(data, &lst_redir, cmd, 'r');
	}
}

void	link_list(t_data *data, t_token **last, t_cmd *cmd, char flag)
{
	if (!*last)
	{
		if (flag == 'a')
			cmd->avlist = data->tokens;
		else
			cmd->redirs = data->tokens;	
	}
	else
		(*last)->nxt = data->tokens;
	(*last) = data->tokens;
	data->tokens = data->tokens->nxt;
	(*last)->nxt = NULL;
}

void	link_cmd(t_data *data, t_cmd **last, t_cmd *cmd)
{
	t_token	*temp;
	
	if (!*last)
		data->cmds = cmd;
	else
		(*last)->nxt = cmd;
	(*last) = cmd;
	(*last)->nxt = NULL;
	if (data->tokens && data->tokens->type == PIPE)
	{	
		temp = data->tokens->nxt;
		free(data->tokens->arg);
		free(data->tokens);
		data->tokens = temp;
	}
}
