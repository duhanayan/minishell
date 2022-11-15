/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:21 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 16:21:22 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_pipe(char *str, int idx)
{
	int	len;	

	len = -1;
	while (str[idx + ++len])
		if (str[idx + len] == '|' && !in_quotes(str, idx + len))
			return (len);
	return (len);
}

void	pipesplit(char *str)
{
	int		idx;
	int		len;
	int		x;
	char	*tmp;

	g_data.pipesplit = alloc_mem(g_data.count_l);
	idx = 0;
	x = -1;
	while (++x < g_data.count_l)
	{
		len = find_pipe(str, idx);
		g_data.pipesplit[x] = ft_substr(str, idx, len);
		tmp = clean_ws(g_data.pipesplit[x]);
		free(g_data.pipesplit[x]);
		g_data.pipesplit[x] = ft_strdup(tmp);
		free(tmp);
		idx += len + 1;
	}
}
