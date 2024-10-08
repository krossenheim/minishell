/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_infile_n_outfile.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 21:49:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 21:50:05 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void clear_tempfile()
{
	int file;
	
	file = open(TEMP_HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	close(file);
}

bool	set_infile(t_hell *dest, t_tkn_dlist *current) 
{	
	int file;
	t_tkn_dlist *next_sep;

	next_sep = get_sep_r(current);
	file = -2;
	if (!next_sep || *next_sep->contents != '<')
		return (true);
	if (dest->infile != -2)
		close(dest->infile);
	if (next_sep->next && *next_sep->contents == '<' && ft_strlen(next_sep->contents) == 1)
		file = open(next_sep->next->contents, O_RDONLY, 0644);	
	else if (next_sep->next && *next_sep->contents == '<' && ft_strlen(next_sep->contents) == 2)
	{
		clear_tempfile();
		heredoc(next_sep->next->contents, (t_mini *) dest->mini);
		file = open(TEMP_HEREDOC,  O_RDONLY, 0666);	
	}
	if (file == -1)
	{
		printf("No permissions to open file. filename: '%s'\n", next_sep->next->contents);
		return (false);
	}
	dest->infile = file;
	return (true);

}	

bool	set_outfile(t_hell *dest, t_tkn_dlist *current)
{
	int file;
	t_tkn_dlist *next_sep;

	next_sep = get_sep_r(current);
	if (!next_sep || *next_sep->contents != '>')
		return (true);
	file = -2;
	if (ft_strncmp(next_sep->contents, ">>", 2) == 0 && ft_strlen(next_sep->contents) == 2)
	{
		if (dest->outfile != -2)
			close(dest->outfile);
		file = open(next_sep->next->contents, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else if (*next_sep->contents == '>' && ft_strlen(next_sep->contents) == 1)
	{
		if (dest->outfile != -2)
			close(dest->outfile);
		file = open(next_sep->next->contents, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (file == -1)
	{
		printf("No permissions to open file. filename: '%s'\n", next_sep->next->contents);
		return (false);
	}
	dest->outfile = file;
	return (true);
}