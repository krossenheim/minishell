/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_infile_n_outfile.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 21:49:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 10:32:33 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	maybe_close(int fd)
{
	if (fd != -2)
		close(fd);
}

bool	set_infile(t_hell *dest, t_tkn_dlist *current)
{
	int			file;
	t_tkn_dlist	*ns;

	ns = get_sep_r(current);
	file = -2;
	if (!ns || *ns->contents != '<')
		return (true);
	if (ns->next && *ns->contents == '<' && ft_strlen(ns->contents) == 1)
	{
		maybe_close(dest->outfile);
		file = open(ns->next->contents, O_RDONLY, 0644);
	}
	else if (ns->next && *ns->contents == '<' && ft_strlen(ns->contents) == 2)
	{
		maybe_close(dest->outfile);
		heredoc(ns->next->contents, (t_mini *) dest->mini);
		file = open(TEMP_HEREDOC, O_RDONLY, 0666);
	}
	if (file == -1)
	{
		printf("No permissions to open file '%s'\n", ns->next->contents);
		return (false);
	}
	dest->infile = file;
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
		file = open(ns->next->contents, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (*ns->contents == '>' && ft_strlen(ns->contents) == 1)
	{
		maybe_close(dest->outfile);
		file = open(ns->next->contents, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file == -1)
	{
		printf("No permissions to open file: '%s'\n", ns->next->contents);
		return (false);
	}
	dest->outfile = file;
	return (true);
}
