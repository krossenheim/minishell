/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/18 16:39:10 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_newline(t_hell *node, int i)
{
	int	j;

	j = 2;
	if (ft_strncmp(node->args[i], "-n", 2) == 0)
	{
		while (node->args[i][j] == 'n')
			j++;
		if (node->args[i][j] == '\0')
			return (0);
	}
	return (-1);
}

int	echo_newline(t_hell *node, int i)
{
	int	j;

	while (node->args[i])
	{
		j = 0;
		while (node->args[i][j])
		{
			write(1, &node->args[i][j], 1);
			j++;
			if (node->args[i][j] == '\0' && node->args[i + 1])
				write(1, " ", 1);
		}
		i++;
	}
	return (0);
}

void	yes_newline(t_hell *node, int i)
{
	int	j;

	j = 0;
	while (node->args[i][j])
	{
		write(1, &node->args[i][j], 1);
		j++;
		if (node->args[i][j] == '\0' && node->args[i + 1])
			write(1, " ", 1);
	}
}

int	program_echo(t_hell *node)
{
	int	i;

	i = 1;
	while (node->args[i])
	{
		if (ft_strncmp(node->args[1], "-n", 3) == 0
			|| (ft_strncmp(node->args[1], "-n", 2) == 0
				&& check_newline(node, i) == 0))
		{
			while ((ft_strncmp(node->args[i], "-n", 3) == 0
					|| check_newline(node, i) == 0) && node->args[i])
				i++;
			echo_newline(node, i);
			return (0);
		}
		yes_newline(node, i);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}
