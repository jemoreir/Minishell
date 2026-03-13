/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_redirs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/11 16:50:57 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redir_list(t_data *data, t_cmd *cmd)
{
	t_token	*redir;
		
	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == I_HDOC || redir->type == I_READ)
		{
			if (cmd->fdin > 1)
				close(cmd->fdin);
			if (redir->type == I_HDOC)
				cmd->fdin = here_doc(data, redir->arg);
			else if (redir->type == I_READ)
				cmd->fdin = open_file(data, redir->arg, 'r');			
		}
		else if (redir->type == O_APPE || redir->type == O_TRUC)
		{
			if (cmd->fdout > 1)
				close(cmd->fdout);
			if (redir->type == O_APPE)
				cmd->fdout = open_file(data, redir->arg, 'a');
			else if (redir->type == O_TRUC)
				cmd->fdout = open_file(data, redir->arg, 't');
		}		
		redir = redir->nxt;
	}		
}

int	here_doc(t_data *data, char *limiter) // inserir flag para saber se tem que expandir as variaveis
{
	int		len;
	int		hd_pipe[2];
	char	*line;

	len = ft_strlen(limiter);
	if (pipe(hd_pipe) == -1)
		exit_error(data, "pipe hdoc", -1);
	ft_putstr_fd("> ", 1);
	while ((line = get_next_line(STDIN_FILENO)))
	{		
		if (!ft_strncmp(line, limiter, len) && line[len] == '\n')
			break ;
		//fazer expasao antes de mandar para fd
		ft_putstr_fd(line, hd_pipe[1]);
		free(line);
		ft_putstr_fd("> ", 1);
	}
	free(line);
	close(hd_pipe[1]);
	return (hd_pipe[0]);
}
	
int	open_file(t_data *data, char *file, char flag)
{
	int	fd;

	check_file(data, file, flag);
	if (flag == 'r')
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			exit_error(data, "read file", -1);
	}
	else
	{
		if (flag == 't')
			fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (flag == 'a')
			fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			exit_error(data, "write file", -1);
	}
	return (fd);
}

void	check_file(t_data *data, char *file, char flag)
{
	if (flag == 'r')
	{
		if (access(file, F_OK) == -1)
			exit_error(data, "file not found", 1);
		if (access(file, R_OK) == -1)
			exit_error(data, "permission denied", 1);
	}
	else
	{
		if (access(file, F_OK) == 0 && access(file, W_OK) == -1)
			exit_error(data, "permission denied", 1);
	}
}
