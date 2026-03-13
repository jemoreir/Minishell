/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:04:35 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/12 09:04:35 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_token	*new_token(t_token_t type, char *value)
{
	t_token	*new;

	if (!value)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
	{
		free(value);
		return (NULL);
	}
	new->type = type;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	token_add_back(t_token **list, t_token *new)
{
	t_token	*tmp;

	if (!list || !new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	tmp = *list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return ;
}

int	token_push(t_token **list, t_token_t ty, char *s, int *i)
{
	t_token	*token;

	if (!s)
		return (3);
	token = new_token(ty, s);
	if (!token)
	{
		free(s);
		return (3);
	}
	if (i)
	{
		if (ty == T_REDIR_APPEND || ty == T_REDIR_HEREDOC)
			(*i) += 2;
		else if (ty != T_WORD)
			(*i) += 1;
	}
	token_add_back(list, token);
	return (0);
}

int	ft_add_op(t_token **tokens, int *i, char *str)
{
	int	err;

	err = 0;
	if (str[*i] == '<' && str[*i + 1] == '<')
		err = token_push(tokens, T_REDIR_HEREDOC, ft_strdup("<<"), i);
	else if (str[*i] == '>' && str[*i + 1] == '>')
		err = token_push(tokens, T_REDIR_APPEND, ft_strdup(">>"), i);
	else if (str[*i] == '|')
		err = token_push(tokens, T_PIPE, ft_strdup("|"), i);
	else if (str[*i] == '>')
		err = token_push(tokens, T_REDIR_OUT, ft_strdup(">"), i);
	else if (str[*i] == '<')
		err = token_push(tokens, T_REDIR_IN, ft_strdup("<"), i);
	return (err);
}

/* int main()
{
	t_token *list = NULL;
	t_token *t = new_token(T_WORD, "ola");
	t_token *a = new_token(T_PIPE, NULL);
	t_token *b = new_token(T_WORD, "mundo");
	t_token *c = new_token(T_WORD, "!");

	token_add_back(&list, t);
	token_add_back(&list, a);
	token_add_back(&list, b);
	token_add_back(&list, c);

	print_tokens(list);
	return (0);
} */