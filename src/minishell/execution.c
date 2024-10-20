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

bool	is_regular_file(char *path, bool verbose_nofile)
{
	struct stat	stat_path;

	if (!path)
		return (false);
	if (!(access(path, F_OK) == 0))
	{
		if (verbose_nofile)
		{
			write(2, "minishell: ", 12);
			write(2, path, ft_strlen(path));
			write(2, ": No such file or directory\n", 29);
		}
		return (false);
	}
	if (stat(path, &stat_path) != 0)
		write(2, "Fatal error could not stat()\n", 30);
	if (S_ISREG(stat_path.st_mode))
		return (true);
	if (S_ISDIR(stat_path.st_mode))
	{
		write(2, "minishell: ", 12);
		write(2, path, ft_strlen(path));
		write(2, ": Is a directory\n", 18);
	}
	return (false);
}

static void	_set_full_path(char **split_mypaths, t_hell *cur)
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
		if (cur->path == NULL && is_regular_file(confirm_path, false))
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
	if (!head->path && is_regular_file(head->args[0], false)
		&& *head->args[0] == '.')
	{
		head->path = ft_strdup(head->args[0]);
	}
	if (!head->path && is_regular_file(head->args[0], false))
		head->path = ft_strdup(head->args[0]);
}

void	ft_set_in_out(t_mini *mini)
{
	mini->saved_stdout = dup(STDOUT_FILENO);
	mini->saved_stdin = dup(STDIN_FILENO);
}

void	ft_pipe(t_hell *head, int fd[2])
{
	if (head->next != NULL)
	{
		if (pipe(fd) == -1)
			perror("pipe");
	}
}
