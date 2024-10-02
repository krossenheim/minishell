/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_stdin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:44:34 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/27 11:39:35 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	count_pipes(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (count);
}

void	first_part_pipe(int *fd, char *child1, char **argv, char **envp)
{
	char	**cmd;
	
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("dup2");
	close(fd[0]);
	cmd = ft_split(argv[2], ' ');
	if (execve(child1, cmd, envp) == -1)
		perror("child1 execve");
	exit (1);
}

// void	second_part_pipe(int *fd, char *child2, char **argv, char **envp)
// {
// 	char	**cmd;

// 	if (dup2(fd[0], STDIN_FILENO) == -1)
// 		perror("dup2");
// 	close(fd[1]);
// 	cmd = ft_split(argv[3], ' ');
// 	if (execve(child2, cmd, envp) == -1)
// 		perror("child2 execve");
// 	exit (1);
// }
void	last_pipe(int *fd, char *child2, char **argv, char **envp)
{
	char	**cmd;

	if (dup2(STDOUT_FILENO, fd[0]) == -1)
		perror("dup2");
	close(fd[1]);
	cmd = ft_split(argv[3], ' ');
	if (execve(child2, cmd, envp) == -1)
		perror("child2 execve");
	exit (1);
}

// void	forks_and_children(t_mini mini, t_hell *list, int j)
// {
// 	int		fd[2];
// 	pid_t	pid;
// 	pid_t	pid1;
// 	int		status;

// 	while (j > 0)
// 	{
// 		pipe(fd);
// 		pid = fork();
// 		if (pid == -1)
// 			exit(1);
// 		if (j == 1 && pid == 0)
// 			last_pipe(fd, list->commands[i], argv, mini.envp);
// 		if (pid == 0)
// 			first_part_pipe(fd, list->commands[i], argv, mini.envp);
// 		// pid1 = fork();
// 		// if (pid1 == -1)
// 		// 	exit(1);
// 		// if (pid != 0 && pid1 == 0)
// 		// 	thebaby(fd, list->commands[i + 1], argv, mini.envp);
		
// 	}
// 	j--;
// }

// char	*find_correct_path(char **spv

// 	i = 0;
// 	while (split_mypaths && split_mypaths[i] != NULL)
// 	{
// 		find_path = ft_strjoin(split_mypaths[i], "/");
// 		confirm_path = ft_strjoin(find_path, cmd[0]);
// 		if (access(confirm_path, F_OK) == 0)
// 		{
// 			free(find_path);
// 			return (confirm_path);
// 		}
// 		else
// 		{
// 			free(find_path);
// 			free(confirm_path);
// 			i++;
// 		}
// 	}
// 	if (access(cmd[0], F_OK) == 0)
// 		return (cmd[0]);
// 	return (NULL);
// }

// int	parse_input(t_mini mini)
// {
// 	char	**pipes;
// 	char	**split_mypaths;
// 	int		i;
// 	int		j;
// 	t_hell	*list;

// 	i = 0;
// 	j = count_pipes(mini.unparsed_input, '|');
// 	pipes = ft_split(mini.unparsed_input, '|');
// 	if (pipes == NULL)	
// 		return (-1);
// 	while (pipes)
// 	{
// 		list->arguments = ft_split(pipes[i], ' ');
// 		//create next node
// 		i++;
// 	}
// 	split_mypaths = ft_split(get_path(mini.envp), ':');
// 	while (list->node->next)
// 	{
// 		i = 0;
// 		// list->commands[i] = find_correct_path(split_mypaths, list->arguments[i]);
// 		i++;
// 	}
// 	forks_and_children(mini, list, j);
// 	return (1);
// }

/*int	parse_input(t_mini mini)
{
	char	**pipes;
	char	*head->args[0];
	char	*head->args;
	int		i;

	i = 0;
	pipes = ft_split(mini.unparsed_input, '|');
	if (pipes == NULL)	
		return (-1);
	while (pipes[i] != NULL)
	{
		head->args[0] = first_word(pipes[i]);
		head->args = not_first_word(pipes[i]);
		printf("Name:%s\nArgs:%s", head->args, head->args);
		check_program(head->args[0], head->args, mini);
		free(head->args[0]);
		free(head->args);
		free(pipes[i]);
		i++;
	}
	free(pipes);
	return (1);
}*/
