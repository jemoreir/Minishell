/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/05 01:02:46 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	t_data data;

	init_data(env, &data);
//	print_heredoc(here_doc(&data, "fim"));			//debbug
	list_tokens(ac, av, &data);
//	print_tokens(data.tokens);						//debbug
	list_cmds(&data);
//	print_lists(&data);								//debbug
	parent_process(&data);
	exit_parent(&data);	
}



/*
check_args(ac, av, env);
void	check_args(int ac, char **av, char **env)
{
	if (ac != 5)
		exit_error(NULL, "argc", 1);
	if (!av[2] || !av[3] || !av[2][0] || !av[3][0])
		exit_error(NULL, "empty", 2);
	if (!ft_getenv("PATH", env))
		exit_error(NULL, "env", 3);
} */