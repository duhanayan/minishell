/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_ws.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:52:58 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 17:52:58 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_ws(char c)
{
	if (c == ' ')
		return (32);
	else if (c == '\t')
		return (9);
	else if (c == '\n')
		return (10);
	else if (c == '\v')
		return (11);
	else if (c == '\f')
		return (12);
	else if (c == '\r')
		return (13);
	return (0);
}

char	*start(char *new_line, char check)
{
	char	*tmp;

	while (check)
	{
		tmp = ft_strtrim(new_line, &check);
		free(new_line);
		new_line = ft_strdup(tmp);
		free(tmp);
		check = is_ws(new_line[0]);
	}
	return (new_line);
}

char	*end(char *new_line, char check)
{
	char	*tmp;

	while (check)
	{
		tmp = ft_strtrim(new_line, &check);
		free(new_line);
		new_line = ft_strdup(tmp);
		free(tmp);
		check = is_ws(new_line[ft_strlen(new_line) - 1]);
	}
	return (new_line);
}

char	*clean_ws(char *str)
{
	char	*new_line;
	char	check;

	check = is_ws(str[0]);
	new_line = ft_strdup(str);
	if (check)
		new_line = start(new_line, check);
	check = is_ws(new_line[ft_strlen(new_line) - 1]);
	if (check)
		new_line = end(new_line, check);
	return (new_line);
}
