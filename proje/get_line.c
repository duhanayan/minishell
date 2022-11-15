/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:31:01 by dayan             #+#    #+#             */
/*   Updated: 2022/11/10 21:31:02 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_input(void)
{
	char	*input;
	char	*prompt;

	prompt = ft_strdup("\033[1;31m|ragoroliptik| -> \033[1;32m");
	input = readline(prompt);
	if (!input)
		return (input);
	free(prompt);
	return (input);
}

char	*take_line(void)
{
	char		*line;

	connectsignals();
	line = get_input();
	signal(SIGINT, nothing);
	if (!line)
		exit(0);
	return (line);
}

void	get_line(void)
{
	char	*line;

	line = take_line();
	g_data.all_line = ft_strdup(line);
	free(line);
	printf("burada\n");
	if (is_command(g_data.all_line))
		add_history(g_data.all_line);
	line = clean_ws(g_data.all_line);
	free(g_data.all_line);
	g_data.all_line = ft_strdup(line);
	free(line);
}
