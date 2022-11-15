/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:54:57 by dayan             #+#    #+#             */
/*   Updated: 2022/11/11 03:36:38 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipe(char *str)
{
	int	counter;
	int	idx;

	counter = 0;
	idx = -1;
	while (str[++idx])
		if (str[idx] == '|' && !in_quotes(str, idx))
			counter++;
	return (counter);
}

void	get_data(void)
{
	g_data.count_l = count_pipe(g_data.all_line) + 1;
	pipesplit(g_data.all_line);
	take_commands(g_data.pipesplit);
	take_args();
}
