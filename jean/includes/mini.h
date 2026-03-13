/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:53 by jemoreir          #+#    #+#             */
/*   Updated: 2026/03/11 20:07:45 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_free_type
{
	T_FREE_LINE,
	T_FREE_TOKENS,
	T_FREE_CMD
}					t_free_t;

typedef enum e_token_type
{
	T_NULL,
	T_PIPE,
	T_WORD,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_REDIR_HEREDOC
}					t_token_t;

typedef struct s_data
{
	char			**cpy_env;
	int				l_exit;
}					t_data;

typedef struct s_token
{
	t_token_t		type;
	char			*value;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd
{
	t_token			*redirs;
	char			**av;
	int				ac;
	char			*infile;
	char			*outfile;
	char			*limiter;
	int				out_append;
	struct s_cmd	*next;
}					t_cmd;

t_token				*new_token(t_token_t type, char *value);
t_token				*lexer(char *str, t_data *d);
void				token_add_back(t_token **list, t_token *new);
void				*print_tokens(t_token *list);
void				free_tokens(t_token *tokens);
char				*token_type_str(t_token_t token);
int					ft_add_word(t_token **tokens, int *i, char *str,
						t_data *data);
int					ft_add_op(t_token **tokens, int *i, char *str);
t_cmd				*create_cmd(void);
void				*free_cmd(t_cmd *cmd);
t_cmd				*parse_pipeline(t_token **tokens, t_data *d);
char				**push_arg(char **av, int ac, t_token *token);
int					parse_redir(t_token **tks, t_cmd *cmd);
int					h_redir_in(t_token **tks, t_cmd *cmd);
int					h_redir_out_append(t_token **tks, t_cmd *cmd);
int					h_redir_heredoc(t_token **tks, t_cmd *cmd);
int					is_redir(t_token *token);
void				print_cmd(t_cmd *cmds);
void				*error_exit(void *ptr, t_free_t ty, int e, t_token *t,
						int *l_exit);
int					print_error(int code, t_token *token);
int					read_quoted(char *str, int *i, char **part, int *qt);
int					read_normal(char *str, int *i, char **part, int *qt);
int					token_push(t_token **list, t_token_t ty, char *s, int *i);
char				*ft_strjoin_mini(char *s1, char *s2);
int					append_join(char **word, char *s);
int					consume_part(t_data *data, char **word, char *part, int qt);
char				*split_mini(char *str, int *i);
int					join_free(t_token **list, char **word, char *tmp,
						int *first);
int					append_expanded(t_data *data, char **word, char *part);
int					free_word_err(int err, char *word);
int					init_name_var(char *var, int *i, char **name);
char				*get_env_value(char *name, char **env);
int					h_var(char *var, t_data *data, int *i, char **res);
int					h_var_last_exit(t_data *data, char **res, int *i);
char				*expand_word(t_data *data, char *part);
int					cpy_env(char **m_env, t_data *data);
t_data				*init_data(void);
int					free_data(t_data *data);
void				free_env(char **env);
int					app_end_char(char *str, char c, char **n_res, int *i);
t_cmd				*put_t_word(t_cmd *cmd, t_token **token, t_data *d);
int					check_last_heredoc(t_token *tokens, int *qt);
void				handler_signal(int sig);

#endif