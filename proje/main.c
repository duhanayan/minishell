/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:17 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 13:51:18 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	special(void)
{
	if (!ft_strcmp(g_data.commands[0], "unset"))
		return (unset());
	else if (!ft_strcmp(g_data.commands[0], "cd"))
		return (cd());
	else if (!ft_strcmp(g_data.commands[0], "export"))
		return (export());
	return (0);
}

void	run(void)
{
	int	**fd;
	int pid;
	int	idx;

	if (g_data.count_l > 1)
	{
		fd = alloc_fd();
		idx = -1;
		while (++idx < g_data.count_l - 1)
			pipe(fd[idx]);
		idx = -1;
		while (++idx < g_data.count_l)
		{
			printf("while içi\n");
			g_data.pids[idx] = fork();
			if (!g_data.pids[idx])
				exec(fd, idx);
		}
		free_fd(fd);
	}
	else if (g_data.count_l == 1)
	{
		idx = 0;
		fd = NULL;
		pid = fork();
		if (!pid)
			exec(fd, idx);
		waitpid(pid, 0, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	take_env(envp);
	while (1)
	{
		get_env();
		get_line();
		get_data();
		if (!ft_strcmp(g_data.commands[0], "exit"))
		{
			free_data();
			free_ezhel(g_data.env);
			system("leaks minishell");
			exit(0);
		}
		if (!special())
			run();
		free_data();
	}
}
