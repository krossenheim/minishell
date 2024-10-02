/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:40:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/25 00:08:42 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	q_esc(char *str, int index)
{
	if (index < 0)
		return (false);
	if (index == 0 && is_quote(str[index]))
		return (false);
	if (index > 1 && str[index - 1] == '\\' && str[index - 2] == '\\')
		return (false);
	if (index > 0 && str[index - 1] == '\\' && is_quote(str[index]))
		return (true);
	return (false);
}

int	in_q(char *str, int index)
{
	int		s;
	int		d;
	int		i;

	i = 0;
	s = 0;
	d = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\'' && !q_esc(str, i) && d % 2 == 0)
			s++;
		if (str[i] == '\"' && !q_esc(str, i) && s % 2 == 0)
			d++;
		if (i == index)
		{
			if (s % 2 != 0 && (q_esc(str, i) || str[i] != '\''))
				return (2);
			if (d % 2 != 0 && (q_esc(str, i) || str[i] != '\"'))
				return (1);
			return (0);
		}
		i++;
	}
	return (-1);
}

static void	fill_argv(char **dest, int size, t_tkn_dlist *current)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		dest[i++] = ft_strdup(current->contents);
		current = current->next;
		size--;
	}
	dest[i++] = NULL;
}

static int	get_argv_array_current_token_size(t_tkn_dlist *current)
{
	t_tkn_dlist	*tmp;
	int			i;

	i = 0;
	tmp = current;
	while (tmp && (tmp->quoted || !is_sep(*tmp->contents)))
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_hell	*init_new_summary(t_tkn_dlist *current)
{
	t_hell		*new;
	int			args_size;

	new = malloc(sizeof(t_hell));
	if (!new)
		return (NULL);
	new->infile = -2;
	new->outfile = -2;
	new->path = NULL;
	args_size = get_argv_array_current_token_size(current);
	new->next = NULL;
	new->args = malloc(sizeof(char *) * (args_size + 1));
	if (!new->args)
	{
		free(new);
		return (NULL);
	}
	new->argc = args_size;
	fill_argv(new->args, args_size, current);
	return (new);
}
