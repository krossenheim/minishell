/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 12:42:16 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	program_exit(t_mini mini)
{
	clear_last_command(&mini);
	ft_clean_exit(&mini);
	exit(0);
}

static int	ft_isalpha(int n)
{
	return ((n >= 97 && n <= 122) || (n >= 65 && n <= 90));
}

static bool	export_formatted(char *export_input)
{
	int i;

	i = 0;
	while (export_input[i] != '\0')
	{
		if (i == 0 && !ft_isalpha(export_input[i]))
		{
			printf("Export variable has to start with alphabetical characters.\n");
			return (0);
		}
		if (export_input[i] == '=' && i > 0)
			return (1);
		i++;
	}
	return (0);
}

static int	_program_export_noargs(t_mini *mini)
{
	t_list *tmp;

	tmp = mini->envp;

	while (tmp != NULL)
	{
		printf("declare -x ");
		printf("%s\n", (char *) tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	program_export(char **args, t_mini *mini) 
{
	t_list *new;
	char	*tmp;
	char	*var_name;
	t_list *envp;

	new = NULL;
	tmp = args[1];
	if (tmp == NULL || ft_strlen(tmp) == 0)
		return (_program_export_noargs(mini));
	if (!(export_formatted(tmp)))
		return (1);
	while (*tmp && *tmp != '=')
		tmp++;
	envp = mini->envp;
	var_name = ft_substr(args[1], 0, tmp - args[1] + 1);
	while (envp)
	{
		if (ft_strncmp(envp->content, var_name, tmp - args[1] + 1) == 0)
		{
			free(envp->content);
			envp->content = ft_strdup(args[1]);
			free(var_name);
			return (0);
		}
		envp = envp->next;
	}		
	free(var_name);
	tmp++;
	if (ft_isspace(*tmp))
		new = ft_lstnew(ft_substr(args[1], 0, tmp - args[1]));
	else
		new = ft_lstnew(first_word(args[1]));
	ft_lstadd_back(&mini->envp, new);
	return (0);
}
