/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:23:28 by dayan             #+#    #+#             */
/*   Updated: 2022/11/09 14:23:29 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_arg_count(char *str)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	printf("STR: %s\n", str);
	while (str[i])
	{
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
				i++;
			i++;
			counter++;
		}
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			i++;
			counter++;
		}
		while (str[i] && is_ws(str[i]) && str[i] != 39 && str[i] != '"')
			i++;
		if (str[i] && str[i] != 39 && str[i] != '"')
			counter++;
		else if (!str[i] && str[i] != 39 && str[i] != '"')
			return (counter);
		while (str[i] && !is_ws(str[i]) && str[i] != 39 && str[i] != '"')
			i++;
	}
	return (counter);
}

void	free_ezhel(char **str)
{
	int	x;

	x = -1;
	while (str[++x])
		free(str[x]);
	free(str);
}

void	free_data(void)
{
	int	i;

	i = -1;
	while (g_data.args[++i])
		free_ezhel(g_data.args[i]);
	free(g_data.args);
	if (g_data.path)
		free_ezhel(g_data.path);
	free_ezhel(g_data.pipesplit);
	free_ezhel(g_data.commands);
	free(g_data.all_line);
}

int	in_env(char	*str)
{
	int		i;
	char	**line;

	i = -1;
	while (g_data.env[++i])
	{
		line = ft_split(g_data.env[i], '=');
		if (!ft_strcmp(line[0], str))
		{
			printf("if içinde free\n");
			free_ezhel(line);
			return (i + 1);
		}
		printf("dışarda free\n");
		free_ezhel(line);
	}
	return (0);
}

int	ft_setenv(char *key, char *value)
{
	int		idx;
	char	*new;

	idx = in_env(key);
	if (idx--)
	{
		free(g_data.env[idx]);
		new = ft_strjoin(key, "=");
		g_data.env[idx] = ft_strjoin(new, value);
		free(new);
		return (1);
	}
	return (0);
}
