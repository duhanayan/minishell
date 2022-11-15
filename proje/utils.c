/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:00:47 by dayan             #+#    #+#             */
/*   Updated: 2022/11/08 14:00:48 by dayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_command(char *input)
{
	int	i;

	i = 0;
	while (input[i])
		if (input[i++] > 32)
			return (1);
	return (0);
}

void	print_args(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("str[%d]: X%sX\n", i, str[i]);
}

int	in_quotes(char *str, int i)
{
	int	d_counter;
	int	s_counter;

	d_counter = 0;
	s_counter = 0;
	while (i >= 0 && str[i])
	{
		if (str[i] == '"')
			d_counter++;
		else if (str[i] == 39)
			s_counter++;
		i--;
	}
	if (d_counter % 2 == 0 && s_counter % 2 == 0)
		return (0);
	else if (d_counter % 2 == 0 && s_counter % 2 != 0)
		return (1);
	else if (d_counter % 2 != 0 && s_counter % 2 == 0)
		return (2);
	return (-1);
}

char	**alloc_mem(int size)
{
	char	**str;

	printf("size: %d\n", size);
	str = malloc(sizeof(char *) * (size + 1));
	str[size] = 0;
	return (str);
}

int	count_arg(char **str)
{
	int	counter;

	counter = 0;
	while (str[++counter])
		;
	return (counter);
}
