/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 14:51:08 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/20 14:39:55 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	_ft_fake_lstclear(t_list *lst)
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	while (lst->prev)
		lst = lst->prev;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
}

static char	**ac_split(t_list *lst)
{
	int				len;
	char			**replaced;
	t_match_info	*cur;

	replaced = malloc(sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!replaced)
		return (NULL);
	len = 0;
	while (lst)
	{
		cur = ((t_match_info *) lst->content);
		replaced[len++] = ft_strdup(cur->name);
		lst = lst->next;
	}
	replaced[len++] = NULL;
	return (replaced);
}

static char	**_autocomplete(DIR	*folder, char *to_match)
{
	t_list		*list;
	char		**autocompleted;

	if (!folder || !to_match)
		return (NULL);
	list = fetch_dir_contents(folder, to_match);
	if (!list)
		return (NULL);
	autocompleted = ac_split(list);
	if ((!autocompleted || !autocompleted[0]) && ft_lstsize(list) > 0)
		write(1, "ERROR\n", 6);
	if (!autocompleted || !autocompleted[0])
		return (NULL);
	_ft_fake_lstclear(list);
	return (autocompleted);
}

static void	autoc_tokens(DIR *folder, t_tkn_dlist *head)
{
	char		**replaced;

	while (head)
	{
		if (head->quoted || ft_strchr(head->contents, '*') == NULL)
		{
			head = head->next;
			continue ;
		}
		replaced = _autocomplete(folder, head->contents);
		if (replaced)
		{
			if (!replace_and_insert(head, replaced))
			{
				write (1, "Error9\n", 7);
				free_split(replaced);
				return ;
			}
		}
		free_split(replaced);
		head = head->next;
	}
}

void	autocomplete(t_mini *mini)
{
	char	*path;
	DIR		*folder;

	path = get_env_var("PWD", *mini);
	if (!path)
		return ;
	folder = opendir(path);
	if (folder == NULL)
		return ;
	autoc_tokens(folder, mini->input_tknized);
	closedir(folder);
}
