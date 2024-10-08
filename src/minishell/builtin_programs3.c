/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs3.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwang <diwang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/26 10:32:14 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/08 18:00:39 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_pwd(t_mini *mini) // return everything after PWD= 
{
	char	*path;
	t_list	*tmp;

	tmp = mini->envp;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
		{
			path = tmp->content + 4;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static void	update_old_pwd(char **args, t_mini *mini) // take "current" PWD=, before changing and add/update it to OLDPWD=
{
	t_list *envp;
	char 	*pwd;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "OLDPWD=", 7) == 0)
			{	
				pwd = get_pwd(mini);
				updated = ft_strjoin("OLDPWD=", pwd);
				free(envp->content);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static	void	update_pwd(char **args, t_mini *mini, char *path) // update the NEW pwd... user input, right?
{
	t_list *envp;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "PWD=", 4) == 0)
			{	
				updated = ft_strjoin("PWD=", path);
				free(envp->content);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static char	*get_cd_path(t_list *envp_list) // for a few edge cases where you always return HOME
{
	char	*path;
	t_list	*tmp;

	tmp = envp_list;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "HOME=", 5) == 0)
		{
			path = tmp->content + 5;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static void	ft_for_home_cd(char **args, t_mini *mini)
{
	char	*confirm_path;
	
	confirm_path = get_cd_path(mini->envp);
	if (confirm_path && access(confirm_path, F_OK) == 0)
	{
		update_old_pwd(args, mini);
		chdir(confirm_path);
		update_pwd(args, mini, confirm_path);
	}
	else
		perror("no such path");
}

static char	*helper_program_pwd()
{
	char	*buf;
	
	buf = getcwd(NULL, 0);
	return (buf);
}

static int	ft_everything_cd(char **args, t_mini *mini)
{
	char *buf;
	
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
		perror("too many arguments");
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