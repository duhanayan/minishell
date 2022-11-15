/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:36:57 by dayan             #+#    #+#             */
/*   Updated: 2022/11/09 23:36:57 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env(void)
{
	int	idx;
	int	arg_count;
	idx = -1;

	arg_count = count_arg(g_data.env);
	while (++idx < arg_count)
		printf("%s\n", g_data.env[idx]);
	exit(0);
}

void	pwd(void)
{
	char	*pwd;

	pwd = getcwd(0, 0);
	printf("%s\n", pwd);
	free(pwd);
	exit(0);
}

void	echo(void)
{
	int	idx;
	int	n;

	idx = 0;
	n = 1;
	if (!ft_strcmp(g_data.args[0][1], "-n"))
	{
		n = 0;
		idx = 1;
	}
	while (g_data.args[0][++idx])
	{
		printf("%s", g_data.args[0][idx]);
		if (g_data.args[0][idx + 1])
			printf(" ");
	}
	if (n)
		printf("\n");
	exit(0);
}

void	forward(void)
{
	return ;
}

void	builtins(void)
{
	if (!ft_strcmp(g_data.commands[0], "env"))
		env();
	else if (!ft_strcmp(g_data.commands[0], "pwd"))
		pwd();
	else if (!ft_strcmp(g_data.commands[0], "echo"))
		echo();
	else if (!ft_strcmp(g_data.commands[0], "export")
		|| !ft_strcmp(g_data.commands[0], "unset")
		|| !ft_strcmp(g_data.commands[0], "cd"))
		forward();
	printf("builtins değil\n");
}
