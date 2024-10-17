/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution3.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:05:59 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/17 13:16:57 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_prev_fd( int *prev_fd)
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

// static void ft_execve(t_hell *head, t_mini *mini)
// {
// 	char	**envp;
	
// 	envp = envp_get(mini);
// 	if (execve(head->path, head->args, envp) == 1)
// 			perror("child execve");
// 	exit(free_split(envp));
// }

// int	ft_main_exec(t_hell *head, t_mini *mini,
// 	int fd[2], int *prev_fd)
// {
// 	pid_t	pid;
// 	char	**envp;
	
// 	ft_pipe(head, fd);
// 	pid = fork();
// 	if (ft_pid(pid) == -1)
// 		return (-1);
// 	if (pid == 0)
// 	{
// 		if (check_correct_command(head) == -1)
// 			return (-1);
// 		if (*prev_fd != -1)
// 			ft_prev_fd(fd);
// 		if (head->next != NULL)
// 			ft_bite_size_write(fd);
// 		ft_redirecs(head);
// 		if (is_builtin(head) == 1)
// 			exit(exec_builtin(head, mini));
// 		else
// 		{
// 			envp = envp_get(mini);
// 			if (execve(head->path, head->args, envp) == 1)
// 				perror("child execve");
// 			exit(free_split(envp));
// 			//ft_execve(head, mini);
// 		}
// 	}
// 	mini->last_pid = pid;
// 	return (pid);
// }

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
		if (check_correct_command(head) == -1)
			return (-1);
		if (*prev_fd != -1)
			ft_prev_fd(fd);
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


