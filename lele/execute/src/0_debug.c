/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbraga <lbraga@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:52:24 by lbraga            #+#    #+#             */
/*   Updated: 2026/03/05 00:58:15 by lbraga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_tokens(t_token *tokens)
{
	ft_printf("list\n");
	while(tokens)
	{
		if (tokens->type == 0)
			ft_printf("WORD");		
		if (tokens->type == 1)
			ft_printf("PIPE");
		if (tokens->type == 2)
			ft_printf("I_HDOC");
		if (tokens->type == 3)
			ft_printf("I_READ");				
		if (tokens->type == 4)
			ft_printf("O_APPE");
		if (tokens->type == 5)
			ft_printf("O_TRUC");
		ft_printf(" = %s\n", tokens->arg);
		tokens = tokens->nxt;
	}
	ft_printf("%s\n", tokens);
}

void	print_lists(t_data *data)
{
	t_cmd	*cmds;

	cmds = data->cmds;	
	while (cmds)
	{
		ft_printf("\nCMD -> %p\n", cmds);
		ft_printf("\nARGS\n");
		print_tokens(cmds->avlist);
		ft_printf("\nREDIRS\n");
		print_tokens(cmds->redirs);
		cmds = cmds->nxt;
	}
	ft_printf("\nCMD -> %p\n", cmds);
}

void	print_cmd(t_cmd *cmd)
{	
	ft_printf("\nCMD -> %p\n", cmd);
	ft_printf("\nARGS\n");
	print_tokens(cmd->avlist);
	ft_printf("\nREDIRS\n");
	print_tokens(cmd->redirs);
	ft_printf("bin = %s\n", cmd->bin);
	ft_printf("fdin = %i\n", cmd->fdin);
	ft_printf("fdout = %i\n", cmd->fdout);
	ft_printf("pid = %i\n", cmd->pid);
	ft_printf("nxt-> %p\n", cmd->nxt);
}

void	print_heredoc(int fd)
{
	char	buffer[11];
	int		bytes;

	while ((bytes = read(fd, buffer, 10)) > 0)
    {
        buffer[bytes] = '\0';
        ft_printf("%s", buffer);
    }
	close(fd);
}



// env "<<" fim "|" ls ">" arquivo