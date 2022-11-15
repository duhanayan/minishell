/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:39 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 13:51:39 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	int		*pids;
	int		count_l;
	int		status;
	char	**env;
	char	**path;
	char	*all_line;
	char	**pipesplit;
	char	**commands;
	char	***args;
}	t_data;

t_data	g_data;

//	builtins.c
void	builtins(void);

//	exec.c
void	set_fd(int **fd, int line);
void	exec(int **fd, int line);

//	get_line.c
char	*take_line(void);
char	*get_input(void);
void	get_line(void);

//	builtins.c
void	env(void);
void	pwd(void);

//	clean_ws.c
int		is_ws(char c);
char	*trim(char *str, char c);
char	*clean_ws(char *str);

//	get_data.c
void	get_data(void);
int		count_pipe(char *str);

//	get_env.c
void	take_env(char **envp);
void	get_env(void);

//	main.c
int		special(void);
void	run(void);

//	pipesplit.c
int		find_pipe(char *str, int idx);
void	pipesplit(char *str);

//	signals.c
void	connectsignals(void);
void	nothing(int sig);
void	signalhandler(int sig);

//	special.c
void	remove_key(int idx, int arg_count, int i);
int		unset(void);
int		cd(void);
int		export(void);

//	take_args.c
int		find_ws_arg(char *str, int idx);
void	argsplit(char *str, int x);
void	take_args(void);

//	take_commands.c
int		find_ws(char *str);
void	take_commands(char **str);

//	utils.c
int		is_command(char *input);
void	print_args(char **str);
int		in_quotes(char *str, int i);
char	**alloc_mem(int size);
int		count_arg(char **str);

//	utils2.c
int		find_arg_count(char *str);
void	free_ezhel(char **str);
void	free_data(void);
int		in_env(char	*str);
int		ft_setenv(char *key, char *value);

//	utils3.c
int		find_size(char *str, char c);
char	**manuelsplit(char *str, char x);
int		find_size_args(char *str);

//	fd.c
void	close_fd(int **fd);
int		**alloc_fd(void);
void	free_fd(int **fd);

#endif
