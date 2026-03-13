#include "mini.h"

char	*get_env_value(char *name, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (env[i])
	{
		if (!ft_strncmp(name, env[i], len) && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	cpy_env(char **m_env, t_data *data)
{
	int	i;

	i = 0;
	while (m_env[i])
		i++;
	data->cpy_env = malloc(sizeof(char *) * (i + 1));
	if (!data->cpy_env)
		return (3);
	i = 0;
	while (m_env[i])
	{
		data->cpy_env[i] = ft_strdup(m_env[i]);
		if (!data->cpy_env[i])
		{
			free_env(data->cpy_env);
			return (3);
		}
		i++;
	}
	data->cpy_env[i] = NULL;
	return (0);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
	return ;
}

char	*expand_word(t_data *data, char *part)
{
	char	*res;
	int		err;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (part[i])
	{
		if (part[i] == '$')
		{
			i++;
			if (part[i] == '?')
				err = h_var_last_exit(data, &res, &i);
			else
				err = h_var(part, data, &i, &res);
		}
		else
			err = app_end_char(res, part[i], &res, &i);
		if (err)
		{
			free(res);
			return (NULL);
		}
	}
	return (res);
}

int	app_end_char(char *str, char c, char **n_res, int *i)
{
	int	t;

	if (str)
		t = ft_strlen(str);
	else
		t = 0;
	*n_res = malloc(t + 2);
	if (!*n_res)
		return (3);
	if (str)
	{
		ft_memcpy(*n_res, str, t);
		free(str);
	}
	(*n_res)[t] = c;
	(*n_res)[t + 1] = '\0';
	(*i)++;
	return (0);
}

int	ft_valid_var_char(int c, int first)
{
	if (first)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}

int	init_name_var(char *var, int *i, char **name)
{
	int	start;
	int	len;

	start = (*i);
	if (!ft_valid_var_char(var[*i], 1))
		return (1);
	(*i)++;
	while (var[*i] && ft_valid_var_char(var[*i], 0))
		(*i)++;
	len = (*i) - start;
	*name = ft_substr(var, start, len);
	if (!*name)
		return (3);
	return (0);
}

t_data	*init_data(void)
{
	t_data *data;

	data = malloc(sizeof (t_data));
	if (!data)
		return (NULL);
	data->cpy_env = NULL;
	data->l_exit = 0;
	return (data);
}

int	free_data(t_data *data)
{
	if (data->cpy_env)
		free_env(data->cpy_env);
	free(data);
	return (0);
}