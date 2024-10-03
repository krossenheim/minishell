/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwang <diwang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 16:14:34 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/03 15:30:01 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	firstborn(int *fd, char *child1, char **argv, char **envp)
{
	char	**cmd;
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("infile");
		exit(1);
	}
	if (child1 == NULL)
	{
		perror("command not found");
		return ;
	}
	if (dup2(infile, STDIN_FILENO) == -1)
		perror("dup2");
	close(infile);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd[0]);
	cmd = ft_split(argv[2], ' ');
	if (execve(child1, cmd, envp) == -1)
		perror("child1 execve");
	exit (1);
}

void	thebaby(int *fd, char *child2, char **argv, char **envp)
{
	char	**cmd;
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("outfile");
		exit(1);
	}
	if (child2 == NULL)
	{
		perror("command not found");
		exit(127);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("dup2");
	if (dup2(outfile, STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd[1]);
	close(outfile);
	cmd = ft_split(argv[3], ' ');
	if (execve(child2, cmd, envp) == -1)
		perror("child2 execve");
	exit (1);
}

void	pipex(char **argv, char *child1, char *child2, char **envp)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid1;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		firstborn(fd, child1, argv, envp);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid != 0 && pid1 == 0)
		thebaby(fd, child2, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, &status, 0);
	waitpid(pid1, &status, 0);
	exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	char	**split_mypaths;
	char	*child1;
	char	*child2;

	if (argc != 5)
	{
		perror("number of arguments");
		exit(0);
	}
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	split_mypaths = ft_split(get_path(envp), ':');
	child1 = find_correct_path(split_mypaths, cmd1);
	child2 = find_correct_path(split_mypaths, cmd2);
	pipex(argv, child1, child2, envp);
	if (child1)
		free(child1);
	if (child2)
		free(child2);
	ft_fr(cmd1);
	ft_fr(cmd2);
	ft_fr(split_mypaths);
	return (0);
}

// open, close, read, write, malloc, free, perror, strerror, access, dup, dup2
// execve, exit, fork, pipe, unlink, wait, waitpid
// examples - grep word, wc -l, wc -w. cat -e
// if (execve(child1, ft_split(argv[2], ' '), envp) == -1)
// 	perror("child1 execve");
