///* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:09:32 by lbraga            #+#    #+#             */
/*   Updated: 2026/02/12 20:07:13 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "src/libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef enum e_type
{
	WORD,	// cmds, flags
	PIPE,	// |
	I_HDOC,	// <<
	I_READ,	// <	
	O_APPE,	// >>
	O_TRUC	// >
}	t_type;

typedef struct s_token
{
	t_type			type;
	char			*arg;
	struct s_token	*nxt;
}	t_token;

typedef struct s_cmd
{
	t_token			*avlist;
	t_token			*redirs;
	char			**argv;
	char			*bin;
	int				fdin;
	int				fdout;
	pid_t			pid;
	struct s_cmd	*nxt;
}	t_cmd;

typedef struct s_data
{
	char	**env;
	char	*path;
	int		pipe[2];	
	t_token	*tokens;
	t_cmd	*cmds;
}	t_data;

void	init_data(char **env, t_data *data);
void	list_tokens(int ac, char **av, t_data *data);
void	retokenize(char *arg, t_token *new, char *nxt_arg);
void	list_cmds(t_data *data);
void	init_cmd(t_cmd *cmd);
void	split_list(t_data *data, t_cmd *cmd);
void	link_list(t_data *data, t_token **last, t_cmd *cmd, char flag);
void	link_cmd(t_data *data, t_cmd **last, t_cmd *cmd);
void	parent_process(t_data *data);
void	child_process(t_data *data, t_cmd *cmd);
void	get_cmd(t_data *data, t_cmd *cmd);
void	array_list(t_data *data, t_cmd *cmd);
void	create_pipe(t_data *data, t_cmd *cmd);
void	get_bin(t_data *data, t_cmd *cmd);
void	redir_list(t_data *data, t_cmd *cmd);
int		here_doc(t_data *data, char *limiter);
int		open_file(t_data *data, char *file, char flag);
void	check_file(t_data *data, char *file, char flag);
// exit
void	exit_error(t_data *data, char *str, int err);
void	exit_parent(t_data *data);
void	clean_cmds(t_cmd *cmd);
void	clean_tokens(t_token *token);
// debug
void	print_tokens(t_token *tokens);
void	print_lists(t_data *data);
void	print_cmd(t_cmd *cmd);
void	print_heredoc(int fd);

#endif