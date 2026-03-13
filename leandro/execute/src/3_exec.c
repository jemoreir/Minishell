/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_exec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/11 16:32:33 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parent_process(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmds;
	while (cmd)
	{
		get_cmd(data, cmd);
//		print_cmd(cmd);								//debbug
		cmd->pid = fork();
		if (cmd->pid == -1)
			exit_error(data, "pid", -1);
		if (cmd->pid == 0)
			child_process(data, cmd);
		else
		{
			if (cmd->fdin > 0)
            	close(cmd->fdin);
        	if (cmd->fdout > 1)
            	close(cmd->fdout);
		}
		cmd = cmd->nxt;
	}
}

void	child_process(t_data *data, t_cmd *cmd)
{
	if (cmd->fdin > 0)
	{
		dup2(cmd->fdin, STDIN_FILENO);
		close(cmd->fdin);
	}
	if (cmd->fdout > 1)
	{
		dup2(cmd->fdout, STDOUT_FILENO);
		close(cmd->fdout);
	}
	if (execve(cmd->bin, cmd->argv, data->env) == -1)
		exit_error(data, "execve", -1);
}

// execve(pasta do comando, comando com as flags, env)