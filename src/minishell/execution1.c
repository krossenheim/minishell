/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution1.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:05:07 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	is_builtin(t_hell *cur)
{
	if (ft_strncmp(cur->args[0], "env", 3) == 0 && ft_strlen(cur->args[0]) == 3)
		return (1);
	if (ft_strncmp(cur->args[0], "unset", 5) == 0 && ft_strlen(cur->args[0]) == 5)
		return (1);
	if (ft_strncmp(cur->args[0], "pwd", 3) == 0 && ft_strlen(cur->args[0]) == 3)
		return (1);
	if (ft_strncmp(cur->args[0], "echo", 4) == 0 && ft_strlen(cur->args[0]) == 4)
		return (1);
	if (ft_strncmp(cur->args[0], "exit", 4) == 0 && ft_strlen(cur->args[0]) == 4)
		return (1);
	if (ft_strncmp(cur->args[0], "export", 6) == 0 && ft_strlen(cur->args[0]) == 6)
		return (1);
	if (ft_strncmp(cur->args[0], "cd", 2) == 0 && ft_strlen(cur->args[0]) == 2)
		return (1);
	return (0);
}

int	exec_builtin(t_hell *head, t_mini *mini)
{
	if (ft_strncmp(head->args[0], "env", 3) == 0 && ft_strlen(head->args[0]) == 3)
		return (program_env(mini));
	else if (ft_strncmp(head->args[0], "unset", 5) == 0 && ft_strlen(head->args[0]) == 5)
		return (program_unset(head, mini));
	else if (ft_strncmp(head->args[0], "pwd", 3) == 0 && ft_strlen(head->args[0]) == 3)
		return (program_pwd());
	else if (ft_strncmp(head->args[0], "echo", 4) == 0 && ft_strlen(head->args[0]) == 4)
		return (program_echo(head));
	else if (ft_strncmp(head->args[0], "exit", 4) == 0 && ft_strlen(head->args[0]) == 4)
		return (program_exit(*mini));
	else if (ft_strncmp(head->args[0], "export", 6) == 0 && ft_strlen(head->args[0]) == 6)
		return (program_export(head->args, mini));
	else if (ft_strncmp(head->args[0], "cd", 2) == 0 && ft_strlen(head->args[0]) == 2)
		return (program_cd(mini));
	return (1);
}