/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs4.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/11 11:12:36 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	export_formatted(char *export_input)
{
	int				i;
	bool	withinvar;

	withinvar = true;
	i = 0;
	while (export_input[i] != '\0')
	{
		if (export_input[i] == '=' && i > 0)
			withinvar = false;
		if (withinvar && !ft_isalpha(export_input[i]))
		{
			write(2, "export: `", 9);
			write(2, export_input, ft_strlen(export_input));
			write(2, " not a valid identifier\n", 25);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	_program_export_noargs(t_mini *mini)
{
	t_list	*tmp;

	tmp = mini->envp;
	while (tmp != NULL)
	{
		printf("declare -x %s\n", (char *) tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

static int	_program_export(t_mini *mini, char	*var_name, char *tmp, char *_)
{
	t_list	*envp;

	envp = mini->envp;
	while (envp)
	{
		if (ft_strncmp(envp->content, var_name, tmp - _ + 1) == 0)
		{
			free(envp->content);
			envp->content = ft_strdup(_);
			free(var_name);
			return (1);
		}
		envp = envp->next;
	}
	free(var_name);
	return (0);
}

int	program_export(char **args, t_mini *mini)
{
	t_list	*new;
	char	*tmp;
	char	*var_name;

	new = NULL;
	tmp = args[1];
	if (tmp == NULL || ft_strlen(tmp) == 0)
		return (_program_export_noargs(mini));
	if (!(export_formatted(tmp)))
		return (1);
	while (*tmp && *tmp != '=')
		tmp++;
	var_name = ft_substr(args[1], 0, tmp - args[1] + 1);
	if (_program_export(mini, var_name, tmp, args[1]) == 1)
		return (0);
	tmp++;
	if (ft_isspace(*tmp))
		new = ft_lstnew(ft_substr(args[1], 0, tmp - args[1]));
	else
		new = ft_lstnew(first_word(args[1]));
	ft_lstadd_back(&mini->envp, new);
	return (0);
}
