/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:05:59 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/23 16:56:56 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_prev_fd(int *prev_fd)
{
	if (dup2(*prev_fd, STDIN_FILENO) == -1)
		perror("dup2 prev_fd");
	close(*prev_fd);
}

static int	check_correct_command(t_hell *head)
{
	if ((!head->path))
	{
		printf("%s: command not found\n", head->args[0]);
		exit(127);
	}
	return (0);
}

static void	ft_execve(t_hell *head, t_mini *mini)
{
	char	**envp;

	envp = envp_get(mini);
	if (execve(head->path, head->args, envp) == 1)
		perror("child execve");
	exit(free_split(envp));
}

int	ft_main_exec(t_hell *head, t_mini *mini,
	int fd[2], int *prev_fd)
{
	pid_t	pid;

	ft_pipe(head, fd);
	pid = fork();
	if (ft_pid(pid) == -1)
		return (-1);
	if (pid == 0)
	{
		check_correct_command(head);
		if (*prev_fd != -1)
			ft_prev_fd(prev_fd);
		if (head->next != NULL)
			ft_bite_size_write(fd);
		ft_redirecs(head);
		if (is_builtin(head) == 1)
			exit(exec_builtin(head, mini));
		else
			ft_execve(head, mini);
	}
	mini->last_pid = pid;
	return (pid);
}
