/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard1.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 14:51:08 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:01:09 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_match_info	*fill_fields(char *name, bool isdir)
{
	t_match_info	*new;

	new = malloc(sizeof(t_match_info));
	if (!new)
		return (NULL);
	new->is_match = true;
	new->isdir = isdir;
	new->name = name;
	return (new);
}

static bool	is_match(char *f, char *m)
{
	if (*f == '.')
		return (false);
	while (*m != '\0' && *f != '\0')
	{
		if (*m == '*')
		{
			while (*m == '*')
				m++;
			while (*f && (*f != *m
					|| (*(m + 1) == '\0' && ft_strchr(f, *m) != NULL)))
				f++;
			if (*f == '\0' && *(f - 1) == *m)
				return (true);
		}
		else if (*f == *m)
		{
			m++;
			f++;
		}
		else
			break ;
	}
	if (*m != '\0' || *f != '\0')
		return (false);
	return (true);
}

static	bool	_fetch_dir_contents(t_list **new,
	t_list **prev,
	struct dirent *entry,
	char *to_match)
{
	struct stat	details;

	if (!is_match(entry->d_name, to_match))
		return (true);
	stat(entry->d_name, &details);
	*new = ft_lstnew(fill_fields(entry->d_name, S_ISDIR(details.st_mode)));
	if (!*new)
		write(1, "Memory error, tear dwown list\n", 31);
	if (!*new)
		return (false);
	(*new)->prev = *prev;
	if (*prev)
		(*prev)->next = *new;
	*prev = *new;
	return (true);
}

t_list	*fetch_dir_contents(DIR	*folder, char *to_match)
{
	struct dirent	*entry;
	t_list			*new;
	t_list			*prev;

	new = NULL;
	prev = NULL;
	entry = readdir(folder);
	while (entry)
	{
		if (!_fetch_dir_contents(&new, &prev, entry, to_match))
		{
			printf("Out of memory while trying to list directory");
			return (NULL);
		}
		entry = readdir(folder);
	}
	if (!new && prev)
		new = prev;
	while (new && new->prev != NULL)
		new = new->prev;
	return (new);
}
