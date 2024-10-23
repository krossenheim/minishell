/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_infile_n_outfile.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 21:49:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/23 13:29:12 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	maybe_close(int fd)
{
	if (fd != -2)
		close(fd);
}

static char	*get_filename(t_tkn_dlist *current)
{
	t_tkn_dlist	*tmp;

	if (!current)
		return (NULL);
	tmp = get_sep_r(current);
	if (!tmp && current->is_sep && current->next)
		return (current->next->contents);
	while (tmp && tmp->next && tmp->is_sep)
		tmp = tmp->next;
	if (!tmp)
		return (NULL);
	return (tmp->contents);
}

static bool	return_true_and_set_cancel_true(t_hell *dest)
{
	dest->cancel = true;
	return (true);
}

bool	set_infile(t_hell *dest, t_tkn_dlist *current)
{
	int			file;
	t_tkn_dlist	*ns;

	ns = get_sep_r(current);
	file = -2;
	if (!ns || *ns->contents != '<' || ns->next->is_sep)
		return (true);
	if (ns->next && *ns->contents == '<' && ft_strlen(ns->contents) == 1)
	{
		if (!is_regular_file(get_filename(current), true))
			return (return_true_and_set_cancel_true(dest));
		maybe_close(dest->outfile);
		file = open(get_filename(current), O_RDONLY, 0644);
	}
	else if (ns->next && *ns->contents == '<' && ft_strlen(ns->contents) == 2)
	{
		maybe_close(dest->outfile);
		heredoc(get_filename(current), (t_mini *) dest->mini);
		file = open(TEMP_HEREDOC, O_RDONLY, 0666);
	}
	if (file > 0)
		dest->infile = file;
	else if (file == -1)
		write(2, "No such file or no permissions\n", 32);
	return (true);
}

bool	set_outfile(t_hell *dest, t_tkn_dlist *current)
{
	int			file;
	t_tkn_dlist	*ns;

	ns = get_sep_r(current);
	if (!ns || *ns->contents != '>')
		return (true);
	file = -2;
	if (ft_strncmp(ns->contents, ">>", 2) == 0 && ft_strlen(ns->contents) == 2)
	{
		maybe_close(dest->outfile);
		file = open(get_filename(ns), O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (*ns->contents == '>' && ft_strlen(ns->contents) == 1)
	{
		maybe_close(dest->outfile);
		file = open(get_filename(ns), O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file > 0)
		dest->outfile = file;
	else if (file == -1)
		write(2, "No such file or no permissions\n", 32);
	dest->outfile = file;
	return (true);
}
