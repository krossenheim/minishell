/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execution.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 16:56:47 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void clear_tempfile()
{
	int file;
	
	file = open(TEMP_HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	close(file);
}

bool	set_infile(t_hell *dest, t_tkn_dlist *current) // <
{	
	int file;
	t_tkn_dlist *next_sep;

	next_sep = get_sep_r(current);
	file = -2;
	if (!next_sep || *next_sep->contents != '<')
		return (true);
	if (dest->infile != -2)
		close(dest->infile);
	if (next_sep->next && *next_sep->contents == '<' && ft_strlen(next_sep->contents) == 1)
		file = open(next_sep->next->contents, O_RDONLY, 0644);	
	else if (next_sep->next && *next_sep->contents == '<' && ft_strlen(next_sep->contents) == 2)
	{
		clear_tempfile();
		heredoc(next_sep->next->contents, (t_mini *) dest->mini);
		file = open(TEMP_HEREDOC,  O_RDONLY, 0666);	
	}
	if (file == -1)
	{
		printf("No permissions to open file. filename: '%s'\n", next_sep->next->contents);
		return (false);
	}
	dest->infile = file;
	return (true);

}	

bool	set_outfile(t_hell *dest, t_tkn_dlist *current) // >
{
	int file;
	t_tkn_dlist *next_sep;

	next_sep = get_sep_r(current);
	if (!next_sep || *next_sep->contents != '>')
		return (true);
	file = -2;
	if (ft_strncmp(next_sep->contents, ">>", 2) == 0 && ft_strlen(next_sep->contents) == 2)
	{
		if (dest->outfile != -2)
			close(dest->outfile);
		file = open(next_sep->next->contents, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (*next_sep->contents == '>' && ft_strlen(next_sep->contents) == 1)
	{
		if (dest->outfile != -2)
			close(dest->outfile);
		file = open(next_sep->next->contents, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file == -1)
	{
		printf("No permissions to open file. filename: '%s'\n", next_sep->next->contents);
		return (false);
	}
	dest->outfile = file;
	return (true);
}

void	set_full_path(t_hell *head, t_mini *mini)
{
	int		i;
	char	*find_path;
	char	*confirm_path;
	char	**split_mypaths;

	head->path = NULL;
	if (is_builtin(head))
	{
		head->path = ft_strdup(head->args[0]);
		return ;
	}
	split_mypaths = ft_split(get_env_var("PATH", *mini), ':');
	i = 0;
	while (split_mypaths && split_mypaths[i] != NULL)
	{
		find_path = ft_strjoin(split_mypaths[i], "/");
		confirm_path = ft_strjoin(find_path, head->args[0]);
		free(find_path);
		if (head->path == NULL && access(confirm_path, F_OK) == 0)
		{
			head->path = confirm_path;
			break ;
		}
		else
			free(confirm_path);
		i++;
	}
	free_split(split_mypaths);
	if (!head->path && access(head->args[0], F_OK) == 0)
		head->path = ft_strdup(head->args[0]);

}

// static	void	ft_is_builtin(t_hell  *head, t_mini *mini, int *prev_fd)
// {
// 	int	fd[2];
	
// 	if (head->next != NULL)
// 	{
// 		if (pipe(fd) == -1)
// 			perror("pipe");
// 		if (dup2(fd[1], STDOUT_FILENO) == -1)
// 			perror("dup2 fd[1]");
// 		close(fd[1]);  
// 		*prev_fd = fd[0];
// 	}
// 	if (head->infile > 0)
// 	{
// 		if (dup2(head->infile, STDIN_FILENO) == -1)
// 			perror("Dup2 error infile");
// 	}
// 	if (head->outfile > 0) 
// 	{
// 		if (dup2(head->outfile, STDOUT_FILENO) == -1)
// 			perror("Dup2 error outfile");
// 	}
// 	exec_builtin(head, mini);
// 	dup2(mini->saved_stdout, STDOUT_FILENO);
// 	dup2(mini->saved_stdin, STDIN_FILENO);
// }

static void 	ft_redirecs(t_hell  *head)
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
// static	void	ft_exit_status(pid_t pid, t_mini mini)
// {
//     waitpid(pid, &mini.last_exit_code, 0);
// }

static void	ft_pipe(t_hell  *head, t_mini *mini, int fd[2])
{
	if (head->next != NULL)
	{
		mini->to_exec->pipe = 1;	
		if (pipe(fd) == -1)
			perror("pipe");
	}
}

static void ft_bite_size_write(int fd[2])
{
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror("dup2 fd[1]");
	close(fd[1]); 
}

static	int	ft_is_not_builtin(t_hell  *head, t_mini *mini, int fd[2], int *prev_fd)
{
	pid_t pid;
	char **envp;
	
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
		envp = envp_get(mini);
		if (execve(head->path, head->args, envp) == 1)
			perror("child execve");
		free_split(envp);
		exit(1);
	}
	mini->last_pid = pid;
	waitpid(pid, &mini->last_exit_code, WNOHANG);
	mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
	return (pid);
}

//waitpid(pid, &mini->last_exit_code, 0);

static	int	ft_is_builtin_new(t_hell  *head, t_mini *mini, int fd[2], int *prev_fd)
{
	pid_t pid;
	
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
	waitpid(pid, &mini->last_exit_code, WNOHANG);
	mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
	return (pid);
}

static void ft_set_in_out(t_mini *mini)
{
	mini->saved_stdout = dup(STDOUT_FILENO);
	mini->saved_stdin = dup(STDIN_FILENO); 
}

static void ft_close_in_out(t_mini *mini)
{
	close(mini->saved_stdout);
    close(mini->saved_stdin);
}

static void	ft_close_redirecs(t_hell  *head)
{
	if (head->infile > 0)
		close(head->infile);

	if (head->outfile > 0)
		close(head->outfile);
}

static void ft_parent(t_hell *head, int fd[2], int *prev_fd)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (head->next != NULL)
	{
		close(fd[1]);  
		*prev_fd = fd[0];  
	}
}

// static	int	ft_exit_status()
// {
// 	int status;
// 	int last;
//     int exit_pid = waitpid(-1, &status, 0);
	
// 	while (exit_pid != -1)
// 	{
// 		if (exit_pid == 0)
// 			last = status;
//     	exit_pid = waitpid(-1, &status, 0);
// 	}
// 	return (last);
// }

// static	int	ft_exit_status()
// {
// 	int status;
// 	int last;
//     int exit_pid = waitpid(-1, &status, 0);
	
// 	while (exit_pid != -1)
// 	{
// 		if (exit_pid == 0)
// 			last = status;
//     	exit_pid = waitpid(-1, &status, 0);
// 	}
// 	return (last);
// }

int execution(t_mini *mini)
{
    t_hell  *head;
    int     fd[2];        
    int     prev_fd;

	prev_fd = -1;
	ft_set_in_out(mini);
    head = mini->to_exec;  
    while (head != NULL)
    {
        if (!head->path)
		{
			printf("Command '%s' not found.\n", head->args[0]);
			mini->last_pid = -1;
			mini->last_exit_code = 127;
		}
		else if (!mini->to_exec->next && is_builtin(head) == 1)
		{
			mini->last_exit_code = exec_builtin(head, mini);
			mini->last_pid = -1;
		}
		else if (is_builtin(head) == 1 && ft_is_builtin_new(head, mini, fd, &prev_fd) != 0)
			ft_parent(head, fd, &prev_fd);
		else if (ft_is_not_builtin(head, mini, fd, &prev_fd) != 0)
			ft_parent(head, fd, &prev_fd);
		ft_close_redirecs(head);
        head = head->next;
    }
	ft_close_in_out(mini);
	if (mini->last_pid >= 0)
	{
		waitpid(mini->last_pid, &mini->last_exit_code, 0);
		mini->last_exit_code = WEXITSTATUS(mini->last_exit_code);
	}
	waitpid(-1, NULL, 0);
	return (1);
}


