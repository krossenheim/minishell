/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wildcard2_a.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 14:51:08 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 22:15:23 by jose-lop      ########   odam.nl         */
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

bool	wildcard2_replace(t_tkn_dlist *to_replace, char **replaced)
{
	free(to_replace->contents);
	to_replace->contents = ft_strdup(replaced[0]);
	if (!to_replace->contents)
		return (false);
	return (true);
}

bool	wildcard2_insert(t_tkn_dlist *to_replace,
				char **replaced,
				t_tkn_dlist *to_insert,
				int lstsize)
{
	int	i;

	i = 1;
	//to_insert->prev = to_replace;
	while (to_insert != NULL)
	{
		if (i == lstsize)
			to_insert->next = to_replace->next;
		if (!copy_nodevals(replaced[i], to_replace, to_insert))
			return (false);
		to_insert = to_insert->next;
		i++;
	}
	if (to_replace->next && to_replace->next->next)
		to_replace->next->next->prev = to_insert;
	return (true);
}
