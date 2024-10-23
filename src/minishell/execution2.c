/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution2.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:05:37 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/23 16:56:27 by jose-lop      ########   odam.nl         */
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

void	ft_one_builtin_cmd(t_mini *mini, t_hell *head)
{
	ft_redirecs(head);
	mini->last_exit_code = exec_builtin(head, mini);
	dup2(mini->saved_stdin, STDIN_FILENO);
	dup2(mini->saved_stdout, STDOUT_FILENO);
	mini->last_pid = -1;
}

void	ft_exit_code_helper(t_mini *mini)
{
	waitpid(mini->last_pid, &mini->last_exit_code, 0);
	mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
}

bool	skip(t_hell **cur)
{
	if ((*cur)->cancel == true)
	{
		*cur = (*cur)->next;
		return (true);
	}
	return (false);
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
		if (skip(&head) == true)
			continue ;
		if (!mini->to_exec->next && is_builtin(head) == 1)
			ft_one_builtin_cmd(mini, head);
		else if (ft_main_exec(head, mini, fd, &p_fd) != 0)
			ft_parent(head, fd, &p_fd);
		ft_close_redirecs(head);
		head = head->next;
	}
	ft_close_in_out(mini);
	if (mini->last_pid >= 0)
		ft_exit_code_helper(mini);
	ft_waitloop();
	return (1);
}
