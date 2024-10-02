/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env_vars.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:30:36 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/19 09:25:58 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*envp_to_linked_list(char **envp)
{
	int		size;
	t_list	*rv;
	t_list	*temp;

	rv = NULL;
	size = 0;
	while (envp != NULL && envp[size])
	{
		temp = ft_lstnew((void *) ft_strdup(envp[size]));
		ft_lstadd_back(&rv, temp);
		size++;
	}
	return (rv);
}

char	*get_env_var(char *name, t_mini mini)
{
	char	*var_value;
	t_list	*tmp;

	if (name == NULL)
		return (NULL);
	tmp = mini.envp;
	var_value = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, name, ft_strlen(name) + 1) == '=')
		{
			var_value = tmp->content;
			break ;
		}
		tmp = tmp->next;
	}
	return (var_value);
}

t_list	*get_env_node(char *name, t_mini mini)
{
	int		varname_len;
	t_list	*tmp;

	tmp = mini.envp;
	varname_len = ft_strlen(name);
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, name, varname_len + 1) == '=')
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
