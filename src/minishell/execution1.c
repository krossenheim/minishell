/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/17 12:27:03 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_hell *cur)
{
	if (ft_strncmp(cur->args[0], "env", 30) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "unset", 50) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "pwd", 30) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "echo", 40) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "exit", 40) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "export", 60) == 0)
		return (1);
	if (ft_strncmp(cur->args[0], "cd", 20) == 0)
		return (1);
	return (0);
}

int	exec_builtin(t_hell *head, t_mini *mini)
{
	if (ft_strncmp(head->args[0], "env", 30) == 0)
		return (program_env(mini));
	else if (ft_strncmp(head->args[0], "unset", 50) == 0)
		return (program_unset(head, mini));
	else if (ft_strncmp(head->args[0], "pwd", 30) == 0)
		return (program_pwd());
	else if (ft_strncmp(head->args[0], "echo", 40) == 0)
		return (program_echo(head));
	else if (ft_strncmp(head->args[0], "exit", 40) == 0)
		return (program_exit(*mini, head));
	else if (ft_strncmp(head->args[0], "export", 60) == 0)
		return (program_export(head->args, mini));
	else if (ft_strncmp(head->args[0], "cd", 20) == 0)
		return (program_cd(mini, head));
	return (1);
}

void	ft_waitloop(void)
{
	while (waitpid(-1, NULL, 0) != -1)
		continue ;
}

int	ft_pid(pid_t pid)
{
	if (pid == -1)
	{
		(perror("fork"));
		return (-1);
	}
	return (0);
}
