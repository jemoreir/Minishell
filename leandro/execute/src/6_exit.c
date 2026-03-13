/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_exit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/05 00:49:30 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(t_data *data, char *str, int err)
{
	if (data)
		clean_cmds(data->cmds);
	if (err == -1)
		perror(str);
	else if (err > 0)
		ft_putendl_fd(str, STDERR_FILENO);
	if (err == 127)
		exit(127);
	exit(1);
}

void	exit_parent(t_data *data)
{	
	int		ext;
	t_cmd	*cmd;

	cmd = data->cmds;
	while (cmd->nxt)
	{
		waitpid(cmd->pid, NULL, 0);
		cmd = cmd->nxt;
	}
	waitpid(cmd->pid, &ext, 0);
	clean_cmds(data->cmds);
	if (WIFEXITED(ext))
		exit(WEXITSTATUS(ext));
	exit(0);
}

void	clean_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd->nxt;
		clean_tokens(cmd->avlist);
		clean_tokens(cmd->redirs);
		ft_arrfree(cmd->argv);		//corrigir arrfree para checar se o array é nulo
		free(cmd->bin);
		free(cmd);
		cmd = tmp;
	}
}

void	clean_tokens(t_token *token)
{
	t_token	*tmp;

	while (token)
	{
		tmp = token->nxt;
		free(token->arg);
		free(token);
		token = tmp;
	}
}
