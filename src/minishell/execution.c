/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   execution.c										:+:	:+:			*/
/*													 +:+					*/
/*   By: jose-lop <jose-lop@student.codam.nl>		 +#+					 */
/*												   +#+					  */
/*   Created: 2024/09/03 12:42:53 by jose-lop	  #+#	#+#				 */
/*   Updated: 2024/10/09 12:41:03 by jose-lop	  ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void	_set_full_path(char **split_mypaths, t_hell *cur)
{
	int		i;
	char	*confirm_path;
	char	*find_path;

	i = 0;
	while (split_mypaths && split_mypaths[i] != NULL)
	{
		find_path = ft_strjoin(split_mypaths[i], "/");
		confirm_path = ft_strjoin(find_path, cur->args[0]);
		free(find_path);
		if (cur->path == NULL && access(confirm_path, F_OK) == 0)
		{
			cur->path = confirm_path;
			break ;
		}
		else
			free(confirm_path);
		i++;
	}
}

void	set_full_path(t_hell *head, t_mini *mini)
{
	char	**split_mypaths;

	if (is_builtin(head))
	{
		head->path = ft_strdup(head->args[0]);
		return ;
	}
	split_mypaths = ft_split(get_env_var("PATH", *mini), ':');
	_set_full_path(split_mypaths, head);
	free_split(split_mypaths);
	if (!head->path && access(head->args[0], F_OK) == 0)
		head->path = ft_strdup(head->args[0]);
}

static void	ft_redirecs(t_hell *head)
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

static void	ft_pipe(t_hell *head, t_mini *mini, int fd[2])
{
	if (head->next != NULL)
	{
		mini->to_exec->pipe = 1;
		if (pipe(fd) == -1)
			perror("pipe");
	}
}

static void	ft_bite_size_write(int fd[2])
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2 fd[1]");
	close(fd[1]);
}

static	void	ft_is_not_builtin_child(int *prev_fd,
	t_hell *head,
	int fd[2],
	t_mini *mini)
{
	char	**envp;

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
	free_split(envp);
	exit(1);
}

static	int	ft_is_not_builtin(t_hell *head,
	t_mini *mini,
	int fd[2],
	int *prev_fd)
{
	pid_t	pid;

	ft_pipe(head, mini, fd);
	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == -1)
		return (-1);
	if (pid == 0)
		ft_is_not_builtin_child(prev_fd, head, fd, mini);
	mini->last_pid = pid;
	return (pid);
}

static	int	ftis(t_hell *head,
	t_mini *mini,
	int fd[2],
	int *prev_fd)
{
	pid_t	pid;

	ft_pipe(head, mini, fd);
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

static void	ft_set_in_out(t_mini *mini)
{
	mini->saved_stdout = dup(STDOUT_FILENO);
	mini->saved_stdin = dup(STDIN_FILENO);
}

static void	ft_close_in_out(t_mini *mini)
{
	close(mini->saved_stdout);
	close(mini->saved_stdin);
}

static void	ft_close_redirecs(t_hell *head)
{
	if (head->infile > 0)
		close(head->infile);
	if (head->outfile > 0)
		close(head->outfile);
}

static void	ft_parent(t_hell *head, int fd[2], int *prev_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (head->next != NULL)
	{
		close(fd[1]);
		*prev_fd = fd[0];
	}
}

static void	_execution(t_hell *h, t_mini *mini, int fd[2], int *prev_fd)
{
	if (!h->path)
	{
		printf("Command '%s' not found.\n", h->args[0]);
		mini->last_pid = -1;
		mini->last_exit_code = 127;
	}
	else if (!mini->to_exec->next && is_builtin(h) == 1)
	{
		ft_redirecs(h);
		mini->last_exit_code = exec_builtin(h, mini);
		mini->last_pid = -1;
		dup2(mini->saved_stdin, STDIN_FILENO);
		dup2(mini->saved_stdout, STDOUT_FILENO);
	}
	else if (is_builtin(h) == 1 && ftis(h, mini, fd, prev_fd) != 0)
		ft_parent(h, fd, prev_fd);
	else if (ft_is_not_builtin(h, mini, fd, prev_fd) != 0)
		ft_parent(h, fd, prev_fd);
	ft_close_redirecs(h);
}

int	execution(t_mini *mini)
{
	t_hell	*h;
	int		fd[2];
	int		prev_fd;

	prev_fd = -1;
	ft_set_in_out(mini);
	h = mini->to_exec;
	while (h != NULL)
	{
		_execution(h, mini, fd, &prev_fd);
		h = h->next;
	}
	ft_close_in_out(mini);
	if (mini->last_pid >= 0)
	{
		waitpid(mini->last_pid, &mini->last_exit_code, 0);
		mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
	}
	while (waitpid(-1, NULL, 0) == 0)
		continue ;
	return (1);
}
