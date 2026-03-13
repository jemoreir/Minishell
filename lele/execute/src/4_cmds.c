/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_cmds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/11 16:31:20 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmd(t_data *data, t_cmd *cmd)
{		
//		check_cmd
		array_list(data, cmd);
		create_pipe(data, cmd);
		redir_list(data, cmd);
//		check_buildin
		get_bin(data, cmd);
//		check full path cmd ex:/bin/ls
//		check pwd command if ./ or / 
}

void	array_list(t_data *data, t_cmd *cmd)
{
	int		i;
	t_token	*avlist;

	i = 0;
	avlist = cmd->avlist;
	while (avlist)
	{
		avlist = avlist->nxt;
		i++;		
	}
	cmd->argv = malloc((i + 1) * sizeof(char *));
	if (!cmd->argv)
		exit_error(data, "malloc argv", 1);
	i = 0;
	avlist = cmd->avlist;
	while (avlist)
	{
		cmd->argv[i] = ft_strdup(avlist->arg);
		if (!cmd->argv[i])
			exit_error(data, "malloc argv", 1);
		avlist = avlist->nxt;
		i++;	
	}
	cmd->argv[i] = NULL;
}

void	create_pipe(t_data *data, t_cmd *cmd)
{
	if (cmd->nxt)
	{
		if (pipe(data->pipe) == -1)
			exit_error(data, "pipe", -1);
		cmd->fdout = data->pipe[1];
		cmd->nxt->fdin = data->pipe[0];
	}
}

void	get_bin(t_data *data, t_cmd *cmd)
{
	int		i;
	char	**paths;
	char	*command;
// 	checar se o ponteiro nulo ou comando vazio
	i = 0;
	command = cmd->argv[0];
	paths = ft_split(data->path, ':');
 	while (paths[i])
	{
		ft_strjoinfree1(&paths[i], "/");
		ft_strjoinfree1(&paths[i], command);
		if (!access(paths[i], F_OK | X_OK))
		{
			cmd->bin = ft_strdup(paths[i]);
			if (!cmd->bin)
				exit_error(data, "malloc bin", 1);
			ft_arrfree(paths);
			return ;
		}
		i++;
	}
	ft_arrfree(paths);
	exit_error(data, "command not found", 127);
}
