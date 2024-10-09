/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs3.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/26 10:32:14 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/09 14:47:22 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*helper_program_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	return (buf);
}

static int	ft_everything_cd(char **args, t_mini *mini)
{
	char	*buf;

	if (access(args[1], F_OK) == 0)
	{
		update_old_pwd(args, mini);
		chdir(args[1]);
		buf = helper_program_pwd();
		update_pwd(args, mini, buf);
		free(buf);
	}
	else
	{
		perror("no such path");
		return (1);
	}
	return (0);
}

int	program_cd(t_mini *mini)
{
	char	**args;

	args = mini->to_exec->args;
	if (mini->to_exec->argc > 2)
	{
		write(mini->saved_stdin, "cd: too many arguments\n", 24);
		return (1);
	}
	if (ft_strncmp(args[0], "cd", 2) == 0 && ft_strlen(args[0]) == 2)
	{
		if ((mini->to_exec->argc == 1)
			&& (ft_strncmp(args[0], "cd", 2) == 0) && ft_strlen(args[0]) == 2)
			ft_for_home_cd(args, mini);
		else if ((ft_strncmp(args[1], "~", 2) == 0) && ft_strlen(args[1]) == 1)
			ft_for_home_cd(args, mini);
		else if (args[1])
			if (ft_everything_cd(args, mini) == 1)
				return (1);
	}
	return (0);
}
