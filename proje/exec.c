/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 03:36:25 by dayan             #+#    #+#             */
/*   Updated: 2022/11/11 03:36:26 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_fd(int **fd, int line)
{
	if (g_data.count_l < 2)
		return ;
	if (line == 0)
		dup2(fd[line][1], 1);
	else if (line < g_data.count_l - 1)
	{
		dup2(fd[line - 1][0], 0);
		dup2(fd[line][1], 1);
	}
	else if (line == g_data.count_l - 1)
		dup2(fd[line - 1][0], 0);
	close_fd(fd);
}

void	no_builtins(int line)
{
	int		idx;
	char	*cmd;

	if (!g_data.path)
		perror("PATH");
	idx = -1;
	while (g_data.path[++idx])
	{
		cmd = ft_strjoin(g_data.path[idx], g_data.commands[line]);
		if (!access(cmd, F_OK))
			execve(cmd, g_data.args[line], g_data.env);
		free(cmd);
	}
}

void	exec(int **fd, int line)
{
	(void) fd;
	if (g_data.count_l > 1)
		set_fd(fd, line);
	
	builtins();
	no_builtins(line);
	printf("Command not found!\n");
	exit(0);
}
