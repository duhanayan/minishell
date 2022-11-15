/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:39:38 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 18:39:38 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_ws_arg(char *str, int idx)
{
	int	len;

	len = 0;
	while (str[idx + len])
	{
		if ((is_ws(str[idx + len]) && !in_quotes(str, idx + len))
			|| !str[idx + len])
			return (len);
		len++;
	}
	return (len);
}

void	quotes(int x, int i, char quotes)
{
	char	*tmp;

	tmp = ft_strtrim(g_data.args[x][i], &quotes);
	free(g_data.args[x][i]);
	g_data.args[x][i] = ft_strdup(tmp);
	free(tmp);
}

void    replace_variable(int x, int i)
{
    char    **old;
    char    *key;
    int        key_idx;
    char    *value;
    char    *tmp;
    char    *new;
    int        idx;
    int        size;

    old = manuelsplit(g_data.args[x][i], '$');
    print_args(old);
    idx = -1;
    if (!ft_strchr(old[0], '$'))
    {
        new = ft_strdup(old[0]);
        idx = 0;
    }
    while (old[++idx])
    {
        size = find_size_args(old[idx] + 1);
        key = ft_substr(old[idx], 1, size);
        key_idx = in_env(key);
        value = ft_strdup("");
        if (key_idx--)
        {
            free(value);
            value = ft_strdup(ft_strchr(g_data.env[key_idx], '=') + 1);
        }
        if (!ft_strchr(old[0], '$'))
        {
            tmp = ft_strjoin(new, value);
            free(new);
            new = ft_strjoin(tmp, ft_strnstr(old[idx], key, ft_strlen(old[idx])) + ft_strlen(key));
			free(tmp);
        }
        else
            new = ft_strjoin(value, ft_strnstr(old[idx], key, ft_strlen(old[idx])) + ft_strlen(key));
        free(value);
        free(key);
    }
    free_ezhel(old);
    free(g_data.args[x][i]);
    g_data.args[x][i] = ft_strdup(new);
	free(new);
}

void	argsplit(char *str, int x)
{
	int		idx;
	int		len;
	int		i;

	idx = 0;
	i = -1;
	while (str[idx])
	{
		while (str[idx] && is_ws(str[idx]))
			idx++;
		if (!str[idx])
			return ;
		len = find_ws_arg(str, idx);
		g_data.args[x][++i] = ft_substr(str, idx, len);
		if (g_data.args[x][i][0] == '"')
		{
			quotes(x, i, '"');
			if (ft_strchr(g_data.args[x][i], '$'))
				replace_variable(x, i);
		}
		else if (g_data.args[x][i][0] == 39)
			quotes(x, i, 39);
		idx += len;
	}
}

void	take_args(void)
{
	int	x;

	g_data.args = malloc(sizeof(char **) * (g_data.count_l + 1));
	g_data.args[g_data.count_l] = 0;
	x = -1;
	while (++x < g_data.count_l)
	{
		print_args(g_data.pipesplit);
		g_data.args[x] = alloc_mem(find_arg_count(g_data.pipesplit[x]));
	}
	x = -1;
	while (++x < g_data.count_l)
		argsplit(g_data.pipesplit[x], x);
}
