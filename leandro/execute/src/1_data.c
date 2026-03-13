/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 20:09:33 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/05 00:16:21 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(char **env, t_data *data)
{	
	data->env = env;
	data->path = ft_getenv("PATH", env);
	data->pipe[0] = -1;
	data->pipe[1] = -1;
	data->tokens = NULL;
	data->cmds = NULL;
}

void	list_tokens(int ac, char **av, t_data *data)
{
	int		i;
	t_token	*new;
	t_token *last;
	
	i = 1;
	last = NULL;
	while (i < ac)
	{
		new = malloc(sizeof(t_token));
		if (!new)
			exit_error(data, "malloc token", EXIT_FAILURE);
		retokenize(av[i], new, av[i + 1]);
		if (!data->tokens)
			data->tokens = new;
		else
			last->nxt = new;
		last = new;
		if (new->type > PIPE)
			i++;
		i++;
	}
}

void	retokenize(char *arg, t_token *new, char *nxt_arg)
{
	if (arg[0] == '|')
		new->type = PIPE;
	else if (arg[0] == '<' && arg[1] == '<')
		new->type = I_HDOC;
	else if (arg[0] == '>' && arg[1] == '>')
		new->type = O_APPE;
	else if (arg[0] == '<')
		new->type = I_READ;
	else if (arg[0] == '>')
		new->type = O_TRUC;
	else
		new->type = WORD;
	if (new->type > PIPE)
		new->arg = ft_strdup(nxt_arg);
	else 
		new->arg = ft_strdup(arg);
	new->nxt = NULL;
}
