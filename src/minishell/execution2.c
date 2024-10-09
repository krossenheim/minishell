/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwang <diwang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:05:37 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/09 14:34:04 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parent(t_hell *head, int fd[2], int *prev_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (head->next != NULL)
	{
		close(fd[1]);
		*prev_fd = fd[0];
	}
}

void	ft_execution_helper(t_mini *mini, t_hell *head)
{
	printf("%s: command not found\n", head->args[0]);
	mini->last_pid = -1;
	mini->last_exit_code = 127;
}

void	ft_execution_helper2(t_mini *mini, t_hell *head)
{
	ft_redirecs(head);
	mini->last_exit_code = exec_builtin(head, mini);
	dup2(mini->saved_stdin, STDIN_FILENO);
	dup2(mini->saved_stdout, STDOUT_FILENO);
	mini->last_pid = -1;
}

void	ft_execution_helper3(t_mini *mini)
{
	waitpid(mini->last_pid, &mini->last_exit_code, 0);
	mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
}

int	execution(t_mini *mini)
{
	t_hell	*head;
	int		fd[2];
	int		p_fd;

	p_fd = -1;
	ft_set_in_out(mini);
	head = mini->to_exec;
	while (head != NULL)
	{
		if (!head->path)
			ft_execution_helper(mini, head);
		else if (!mini->to_exec->next && is_builtin(head) == 1)
			ft_execution_helper2(mini, head);
		else if (is_builtin(head) == 1 && ft_newbi(head, mini, fd, &p_fd) != 0)
			ft_parent(head, fd, &p_fd);
		else if (ft_is_not_builtin(head, mini, fd, &p_fd) != 0)
			ft_parent(head, fd, &p_fd);
		ft_close_redirecs(head);
		head = head->next;
	}
	ft_close_in_out(mini);
	if (mini->last_pid >= 0)
		ft_execution_helper3(mini);
	ft_waitloop();
	return (1);
}
