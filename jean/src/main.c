/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:14:44 by jemoreir          #+#    #+#             */
/*   Updated: 2026/03/13 20:10:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	main(int ac, char **av, char **env)
{
	char *line;
	t_token *tokens;
	t_token *cur;
	t_cmd *cmd;
	t_data *data;
	(void)ac;
	(void)av;

	data = init_data();
	if (!data)
		return (3);
	cpy_env(env, data);
	signal(SIGINT, handler_signal);

	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(1, "exit\n", 5);
			break ;
		}
		if (*line)
			add_history(line);
		tokens = lexer(line, data);
		if (!tokens)
		{
			free(line);
			continue ;
		}
		cur = tokens;
		cmd = parse_pipeline(&cur, data);
		if (cmd)
		{
			print_cmd(cmd);
			free_cmd(cmd);
		}
		free_tokens(tokens);
		free(line);
	}
	free_data(data);
	clear_history();
	return (0);
}