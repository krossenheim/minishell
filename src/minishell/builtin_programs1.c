/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 21:24:09 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	program_env(t_mini *mini)
{
	t_list	*tmp;

	tmp = mini->envp;
	while (tmp != NULL)
	{
		printf("%s\n", (char *) tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	program_pwd(void)
{
	char	buffer[1000];
	char	*buf;

	buf = getcwd(buffer, 1000);
	if (buf == NULL)
	{
		free(buf);
		return (1);
	}
	printf("%s\n", buffer);
	return (0);
}

static bool	has_newline(t_hell *to_exec, int *i)
{
	char	*tmp;

	tmp = to_exec->args[*i];
	if (to_exec->argc <= 1)
		return (false);
	if (ft_strncmp(to_exec->args[*i], "-n", 2) == 0)
	{
		tmp = tmp + 2;
		while (*tmp)
		{
			if (*tmp != 'n')
				return (false);
			tmp++;
		}
		return (true);
	}
	return (false);
}

static void	_program_echo(t_hell *to_exec, int *i)
{
	int	j;

	j = 0;
	while (to_exec->args[*i][j])
	{
		write(1, &to_exec->args[*i][j], 1);
		j++;
	}
	if (to_exec->args[*i + 1])
		write(1, " ", 1);
	(*i)++;
}

int	program_echo(t_hell *to_exec)
{
	int		i;
	bool	newline;

	i = 1;
	newline = true;
	if (has_newline(to_exec, &i))
	{
		i++;
		newline = false;
	}
	while (to_exec->argc > i)
		_program_echo(to_exec, &i);
	if (newline)
		write(1, "\n", 1);
	return (0);
}
