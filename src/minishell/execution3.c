/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:05:59 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/11 15:16:04 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_not_builtin(t_hell *head, t_mini *mini,
	int fd[2], int *prev_fd)
{
	pid_t	pid;
	char	**envp;

	ft_pipe(head, fd);
	pid = fork();
	if (ft_pid(pid) == -1)
		return (-1);
	if (pid == 0)
	{
		if (*prev_fd != -1)
		{
			if (dup2(*prev_fd, STDIN_FILENO) == -1)
				perror("dup2 prev_fd");
			close(*prev_fd);
		}
		if (head->next != NULL)
			ft_bite_size_write(fd);
		ft_redirecs(head);
		envp = envp_get(mini);
		if (execve(head->path, head->args, envp) == 1)
			perror("child execve");
		exit(free_split(envp));
	}
	mini->last_pid = pid;
	return (pid);
}

int	ft_newbi(t_hell *head,
	t_mini *mini, int fd[2], int *prev_fd)
{
	pid_t	pid;

	ft_pipe(head, fd);
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		if (*prev_fd != -1)
		{
			if (dup2(*prev_fd, STDIN_FILENO) == -1)
				perror("dup2 prev_fd");
			close(*prev_fd);
		}
		if (head->next != NULL)
			ft_bite_size_write(fd);
		ft_redirecs(head);
		exit(exec_builtin(head, mini));
	}
	mini->last_pid = pid;
	return (pid);
}

void	ft_close_in_out(t_mini *mini)
{
	close(mini->saved_stdout);
	close(mini->saved_stdin);
}

void	ft_close_redirecs(t_hell *head)
{
	if (head->infile > 0)
		close(head->infile);
	if (head->outfile > 0)
		close(head->outfile);
}

void	ft_redirecs(t_hell *head)
{
	if (head->infile > 0)
	{
		if (dup2(head->infile, STDIN_FILENO) == -1)
			perror("Dup2 error infile");
	}
	if (head->outfile > 0)
	{
		if (dup2(head->outfile, STDOUT_FILENO) == -1)
			perror("Dup2 error outfile");
	}
}
