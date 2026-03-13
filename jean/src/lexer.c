/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jemoreir <jemoreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:03:54 by jemoreir          #+#    #+#             */
/*   Updated: 2026/02/12 09:03:54 by jemoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

int	consume_part(t_data *data, char **word, char *part, int qt)
{
	if (qt == 1)
		return (append_join(word, part));
	return (append_expanded(data, word, part));
}

int	ft_add_word(t_token **tokens, int *i, char *str, t_data *data)
{
	char	*word;
	char	*part;
	int		err;
	int		qt;

	word = NULL;
	while (str[*i] && !ft_isspace(str[*i]) && !ft_is_op(str[*i]))
	{
		part = NULL;
		qt = ft_is_quote(str[*i]);
		if (qt)
			err = read_quoted(str, i, &part, &qt);
		else
			err = read_normal(str, i, &part, &qt);
		if (err)
			return (free_word_err(err, word));
		check_last_heredoc(*tokens, &qt);
		err = consume_part(data, &word, part, qt);
		free(part);
		if (err)
			return (free_word_err(err, word));
	}
	return (token_push(tokens, T_WORD, word, NULL));
}

int	read_quoted(char *str, int *i, char **part, int *qt)
{
	char	quote;
	int		start;

	quote = str[*i];
	*qt = ft_is_quote(quote);
	(*i)++;
	start = (*i);
	while (str[*i] && str[*i] != quote)
		(*i)++;
	if (!str[*i])
		return (1);
	*part = ft_substr(str, start, (*i) - start);
	if (!*part)
		return (3);
	(*i)++;
	printf("Parte: [%s] -> veio de [%c]\n", *part, quote);
	return (0);
}

int	read_normal(char *str, int *i, char **part, int *qt)
{
	int	start;

	start = (*i);
	*qt = 0;
	while (str[*i] && !ft_is_acceptable(str[*i]))
		(*i)++;
	*part = ft_substr(str, start, (*i) - start);
	if (!*part)
		return (3);
	printf("Parte: [%s] -> veio de [unquoted]\n", *part);
	return (0);
}

t_token	*lexer(char *str, t_data *d)
{
	int		i;
	int		err;
	t_token	*tokens;

	i = 0;
	err = 0;
	tokens = NULL;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			i++;
		else if (ft_is_op(str[i]))
			err = ft_add_op(&tokens, &i, str);
		else
			err = ft_add_word(&tokens, &i, str, d);
		if (err)
			return (error_exit(tokens, T_FREE_TOKENS, err, NULL, &d->l_exit));
	}
	return (tokens);
}

/* int	main(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		printf("---- // ---\n");
		t_token *tokens = lexer(av[i]);
		print_tokens(tokens);
		free_tokens(tokens);
		printf("--- // ---\n");
	}
} */