/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:36:52 by dayan             #+#    #+#             */
/*   Updated: 2022/11/09 23:36:53 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_key(int idx, int arg_count, int i)
{
	char	**line;
	char	**new_env;
	int		j;

	new_env = malloc(sizeof(char *) * arg_count); // -1 silindi
	if (!new_env)
	{
		printf("yer açamadı\n");
		return ;
	}
	i = -1;
	j = -1;
	while (g_data.env[++j])
	{
		line = ft_split(g_data.env[j], '=');
		if (!ft_strcmp(g_data.args[0][idx], line[0]))
			j++;
		if (!g_data.env[j])
		{
			free_ezhel(line);
			break ;  // return ile dene;
		}
		new_env[++i] = ft_strdup(g_data.env[j]);
		free_ezhel(line);
	}
	new_env[++i] = 0;
	free_ezhel(g_data.env);
	arg_count = count_arg(new_env);
	g_data.env = malloc(sizeof(char *) * (arg_count + 1));
	g_data.env[arg_count] = 0;
	i = -1;
	while(new_env[++i])
		g_data.env[i] = ft_strdup(new_env[i]);
	free_ezhel(new_env);
}

int	unset(void)
{
	int	idx;
	int	arg_count;
	int	i;

	idx = 0;
	i = 0;
	print_args(g_data.args[0]);
	while (g_data.args[0][++idx])
	{
		printf("girdi unset\n");
		printf("args[0][%d]: %s\n", idx, g_data.args[0][idx]);
		if (!in_env(g_data.args[0][idx]))
		{
			printf("furkan2\n");
			continue ;
		}
		printf("furkan \n");
		arg_count = count_arg(g_data.env);
		printf("girdi 2\n");
		remove_key(idx, arg_count, i);
		printf("girdi 3\n");
	}
	return (1);
}

int	cd(void)
{
	char	*pwd;
	int		ret;

	ret = 1;
	pwd = getcwd(0, 0);
	if (!g_data.args[0][1] || !ft_strcmp(g_data.args[0][1], "~"))
		ret = chdir(getenv("HOME"));
	else if (!ft_strcmp(g_data.args[0][1], "/"))
		ret = chdir("/");
	else
		ret = chdir(g_data.args[0][1]);
	if (ret)
	{
		perror("cd");
		free(pwd);
		return (0);
	}
	ft_setenv("OLDPWD", pwd);
	free(pwd);
	pwd = getcwd(0, 0);
	ft_setenv("PWD", pwd);
	free(pwd);
	return (1);
}

void	creat_env(int idx)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * ((count_arg(g_data.env) + 1) + 1));
	new_env[count_arg(g_data.env) + 1] = 0; // + 2 idi
	i = -1;
	while (g_data.env[++i])
		new_env[i] = ft_strdup(g_data.env[i]);
	new_env[i] = ft_strdup(g_data.args[0][idx]);
	new_env[++i] = 0;
	i = -1;
	free_ezhel(g_data.env);
	g_data.env = malloc(sizeof(char *) * (count_arg(new_env) + 1));
	while (new_env[++i])
		g_data.env[i] = ft_strdup(new_env[i]);
	g_data.env[i] = 0;
	free_ezhel(new_env);
}

int	export(void)
{
	int		idx;
	char	**arg_sep;

	idx = 0;
	while (g_data.args[0][++idx])
	{
		arg_sep = ft_split(g_data.args[0][idx], '=');
		if (!ft_setenv(arg_sep[0], arg_sep[1]))
			creat_env(idx);
		free_ezhel(arg_sep);
	}
	return (1);
}
