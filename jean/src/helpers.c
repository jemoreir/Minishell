/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:37:27 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/23 15:37:27 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	is_redir(t_token *token)
{
	return (token->type == T_REDIR_HEREDOC || token->type == T_REDIR_APPEND
		|| token->type == T_REDIR_IN || token->type == T_REDIR_OUT);
}

char	*ft_strjoin_mini(char *s1, char *s2)
{
	char	*res;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	res = malloc(sizeof(char) * (len + ft_strlen(s2)) + 1);
	if (!res)
		return (NULL);
	if (s1)
	{
		ft_memcpy(res, s1, ft_strlen(s1));
		free(s1);
	}
	ft_memcpy(res + len, s2, ft_strlen(s2));
	res[len + ft_strlen(s2)] = '\0';
	return (res);
}

int	append_join(char **word, char *s)
{
	char	*tmp;

	tmp = ft_strjoin_mini(*word, s);
	if (!tmp)
		return (3);
	*word = tmp;
	return (0);
}

char	*split_mini(char *str, int *i)
{
	int		start;
	char	*res;

	while (str[*i] && ft_isspace(str[*i]))
		(*i)++;
	if (!str[*i])
		return (NULL);
	start = (*i);
	while (str[*i] && !ft_isspace(str[*i]))
		(*i)++;
	res = ft_substr(str, start, (*i) - start);
	if (!res)
		(*i) = -1;
	return (res);
}

int	append_expanded(t_data *data, char **word, char *part)
{
	char	*expanded;
	int		err;

	err = 0;
	expanded = expand_word(data, part);
	if (!expanded)
		return (3);
	err = append_join(word, expanded);
	free(expanded);
	return (err);
}

int	check_last_heredoc(t_token *tokens, int *qt)
{
	t_token *tmp;

	if (!tokens)
		return (0);
	tmp = tokens;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->type == T_REDIR_HEREDOC)
	{
		(*qt) = 1;
		return (1);
	}
	return (0);
}
