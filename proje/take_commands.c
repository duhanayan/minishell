/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:18:32 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 18:18:32 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_ws(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		if (is_ws(str[idx]) && !in_quotes(str, idx))
			return (idx);
	return (idx);
}

void	take_commands(char **str)
{
	int		len;
	int		x;
	char	*tmp;

	g_data.commands = alloc_mem(g_data.count_l);
	x = -1;
	while (++x < g_data.count_l)
	{
		len = find_ws(str[x]);
		g_data.commands[x] = ft_substr(str[x], 0, len);
		if (ft_strchr(g_data.commands[x], '"'))
		{
			tmp = ft_strtrim(g_data.commands[x], "\"");
			free(g_data.commands[x]);
			g_data.commands[x] = ft_strdup(tmp);
			free(tmp);
		}
		if (ft_strchr(g_data.commands[x], 39))
		{
			tmp = ft_strtrim(g_data.commands[x], "'");
			free(g_data.commands[x]);
			g_data.commands[x] = ft_strdup(tmp);
			free(tmp);
		}
	}
}
