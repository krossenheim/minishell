/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 14:51:08 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/20 13:44:28 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	copy_nodevals(char *new_str, t_tkn_dlist *src, t_tkn_dlist *dest)
{
	if (!src || !dest || !new_str)
		return (false);
	dest->contents = ft_strdup(new_str);
	if (!dest->contents)
	{
		write(1, "OUT OF MEMORY\n", 15);
		return (false);
	}
	dest->quoted = src->quoted;
	dest->is_sep = src->is_sep;
	return (true);
}

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

bool	replace_and_insert(t_tkn_dlist *tmp, char **replaced)
{
	int			i;
	t_tkn_dlist	*left;
	t_tkn_dlist	*right;
	t_tkn_dlist	*to_insert;
	int			lstsize;

	if (!tmp || !replaced)
		return (false);
	lstsize = split_len(replaced);
	left = tmp;
	right = tmp->next;
	to_insert = empty_dlist(lstsize - 1);
	if (left)
		left->next = to_insert;
	free(tmp->contents);
	tmp->contents = ft_strdup(replaced[0]);
	if (!tmp->contents)
		return (false);
	if (lstsize == 1)
		return (true);
	i = 1;
	while (to_insert != NULL)
	{
		if (i == 0)
			to_insert->prev = left;
		if (i == lstsize)
			to_insert->next = right;
		if (!copy_nodevals(replaced[i], tmp, to_insert))
			return (false);
		to_insert = to_insert->next;
		i++;
	}
	if (right && right->next)
		right->next->prev = to_insert;
	return (true);
}