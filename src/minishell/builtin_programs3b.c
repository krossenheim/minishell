/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs3b.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/26 10:32:14 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/08 21:36:56 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(t_mini *mini)
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

void	update_old_pwd(char **args, t_mini *mini)
{
	t_list	*envp;
	char	*pwd;
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

void	update_pwd(char **args, t_mini *mini, char *path)
{
	t_list	*envp;
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

char	*get_cd_path(t_list *envp_list)
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

void	ft_for_home_cd(char **args, t_mini *mini)
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
