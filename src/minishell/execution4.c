/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution4.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/15 14:33:17 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/15 14:47:05 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	ft_bite_size_write(int fd[2])
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2 fd[1]");
	close(fd[1]);
}
