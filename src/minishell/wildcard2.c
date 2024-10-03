/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 14:51:08 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:00:08 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_tkn_dlist	*empty_dlist(int size)
{
	t_tkn_dlist	*new;
	t_tkn_dlist	*prev;
	int			i;

	if (size < 1)
		return (NULL);
	prev = NULL;
	i = 0;
	while (size > i)
	{
		new = malloc(sizeof(t_tkn_dlist));
		if (!new)
			return (NULL);
		new->prev = prev;
		new->next = NULL;
		if (prev)
			prev->next = new;
		prev = new;
		i++;
	}
	while (new->prev)
		new = new->prev;
	return (new);
}

static int	split_len(char **s)
{
	int	l;

	l = 0;
	while (s && s[l])
		l++;
	return (l);
}

bool	replace_and_insert(t_tkn_dlist *to_replace, char **replaced)
{
	t_tkn_dlist	*to_insert;
	int			lstsize;

	if (!to_replace || !replaced)
		return (false);
	lstsize = split_len(replaced);
	to_insert = empty_dlist(lstsize - 1);
	to_replace->next = to_insert;
	if (!wildcard2_replace(to_replace, replaced))
		return (false);
	if (lstsize == 1)
		return (true);
	wildcard2_insert(to_replace, replaced, to_insert, lstsize);
	return (true);
}
