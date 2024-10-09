/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:35:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 17:59:25 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tkn_dlist	*get_sep_r(t_tkn_dlist *current)
{
	t_tkn_dlist	*tmp;

	if (!current)
		return (NULL);
	tmp = current;
	while (tmp->next)
	{
		if (tmp->next && is_sep(*tmp->next->contents) && !tmp->next->quoted)
			return (tmp->next);
		tmp = tmp->next;
	}
	return (NULL);
}

static t_tkn_dlist	*next_token_init(char *spaced_line, int *i)
{
	t_tkn_dlist		*new;

	if (!(spaced_line) || spaced_line[*i] == '\0')
		return (NULL);
	new = malloc(sizeof(t_tkn_dlist));
	if (new == NULL)
	{
		write(1, "Fatal malloc error; go clean up!\n\nNOOOW!\n", 42);
		return (NULL);
	}
	new->next = NULL;
	new->prev = NULL;
	new->is_sep = false;
	new->quoted = false;
	if (is_quote(spaced_line[*i]))
		new->quoted = true;
	return (new);
}

static bool	fill_token(char *str, int *i, t_tkn_dlist *new, t_mini *mini)
{
	int	size;

	if (!new)
	{
		write(1, "null  token !", 14);
		return (false);
	}
	size = calculate_expanded_len(str + (*i), mini) + 1;
	new->contents = malloc(sizeof(char ) * size);
	if (new->contents == NULL)
		write(1, "Mallloc error", 14);
	write_tkn(str, i, new, *mini);
	if (is_sep(*new->contents) && !new->quoted)
		new->is_sep = true;
	return (true);
}

int	tokenize_input(t_mini *mini, char *spaced_line)
{
	int			i;
	t_tkn_dlist	*prev;
	t_tkn_dlist	*next;

	prev = NULL;
	i = 0;
	while (spaced_line[i])
	{
		ft_skip_spaces(spaced_line, &i);
		next = next_token_init(spaced_line, &i);
		if (!next && !prev)
			return (-1);
		if (fill_token(spaced_line, &i, next, mini) == false)
			write(1, "Somethign went wrong filling the token.", 40);
		ft_skip_spaces(spaced_line, &i);
		next->prev = prev;
		if (prev)
			prev->next = next;
		prev = next;
	}
	while (next->prev)
		next = next->prev;
	mini->input_tknized = next;
	return (1);
}
