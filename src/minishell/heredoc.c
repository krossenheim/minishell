/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 10:19:51 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 14:16:09 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_killsig;

void	killdoc(int _)
{
	if (0 && _)
		exit(2);
	g_killsig = 1;
}

void	child_process(char *marker, int fd, t_mini *mini)
{
	char	*line;

	while (g_killsig == 0)
	{
		line = readline("> ");
		if (ft_strncmp(marker, line, INT_MAX) == 0)
		{
			free(line);
			break ;
		}
		expanded_vars(line, fd, *mini);
		free(line);
	}
	close(fd);
	exit(1);
}

static void	bind_heredoc_signals_and_cleartemp(void)
{
	int	file;

	file = open(TEMP_HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (file > 0)
		close(file);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, killdoc);
}

static void	bind_back_to_default(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

bool	heredoc(char *marker, t_mini *mini)
{
	int		fd[2];
	int		status;
	int		child_pid;

	status = 0;
	bind_heredoc_signals_and_cleartemp();
	pipe(fd);
	fd[0] = open(TEMP_HEREDOC, O_RDWR | O_CREAT | O_APPEND, 0666);
	if (!fd[0] || dup2(fd[0], fd[1]) == -1)
	{
		write(1, "Heredoc Dup2 failure\n", 22);
		return (false);
	}
	g_killsig = 0;
	child_pid = fork();
	if (child_pid == -1)
		return (false);
	if (child_pid == 0)
		child_process(marker, fd[1], mini);
	while (g_killsig == 0 && WEXITSTATUS(status) == 0)
		waitpid(child_pid, &status, WNOHANG);
	kill(child_pid, SIGQUIT);
	bind_back_to_default();
	close(fd[0]);
	return (!g_killsig);
}
