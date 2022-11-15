/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:19:24 by dayan             #+#    #+#             */
/*   Updated: 2022/11/12 14:19:26 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_char(char *str, char x)
{
	int	idx;
	int	counter;

	idx = -1;
	counter = 0;
	while (str[++idx])
		if (str[idx] == x)
			counter++;
	return (counter);
}

int	find_size(char *str, char c)
{
	int	size;

	size = 0;
	while (str[++size])
		if (str[size] == c)
			return (size);
	return (size);
}

char	**manuelsplit(char *str, char x)
{
	char	**new;
	char	*tmp;
	int		idx;
	int		size;
	int		j;

	idx = 0;
	new = alloc_mem(count_char(str, x) + 1);
	j = -1;
	while (str[idx])
	{
		size = find_size(str + idx, x);
		tmp = ft_substr(str, idx, size);
		new[++j] = ft_strdup(tmp);
		free(tmp);
		idx += size;
	}
	return (new);
}

int	find_size_args(char *str)
{
	int	idx;

	idx = -1;
	while (str[++idx])
		if (is_ws(str[idx]) || str[idx] == 39)
			return (idx);
	return (idx);
}
