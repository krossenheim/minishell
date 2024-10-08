/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 12:23:53 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*first_word_has_no_quotes(char *has_no_quotes)
{
	char	*tmp;

	if (ft_strchr(has_no_quotes, ' ') == NULL)
		return (ft_strdup(has_no_quotes));
	tmp = has_no_quotes;
	while (ft_isspace(*tmp))
		tmp++;
	return (ft_substr(tmp, 0, ft_strchr(tmp, ' ') - tmp));
}

static void	_first_word_is_quoted(char *mb_hasq,
	int *idx_end,
	int *idx_begin,
	int *offset)
{
	int	i;

	i = 0;
	while (mb_hasq[i] != '\0' && *idx_end == -1)
	{
		if (is_quote(mb_hasq[i]))
		{
			if (*idx_begin == -1)
				*idx_begin = i;
			else if (*idx_end == -1 && mb_hasq[i] == mb_hasq[*idx_begin])
				*idx_end = i;
		}
		if (i > 0 && !ft_isspace(mb_hasq[i])
			&& !is_quote(mb_hasq[i]) && *idx_begin == -1)
			break ;
		else if (*idx_begin == -1)
			(*offset)++;
		i++;
	}
}

char	*first_word_is_quoted(char *mb_hasq)
{
	int	idx_begin;
	int	idx_end;
	int	offset;

	idx_begin = -1;
	idx_end = -1;
	offset = 0;
	_first_word_is_quoted(mb_hasq, &idx_end, &idx_begin, &offset);
	if (idx_end == -1)
		return (NULL);
	return (ft_substr(mb_hasq, idx_begin + 1, idx_end - 1 - offset));
}

char	*first_word(char *may_have_quotes)
{
	char	*rv;

	rv = NULL;
	while (ft_isspace(*may_have_quotes))
		may_have_quotes++;
	if (may_have_quotes == NULL || ft_strlen(may_have_quotes) == 0)
		rv = ft_strdup("\0");
	if (rv != NULL)
		return (rv);
	rv = first_word_is_quoted(may_have_quotes);
	if (rv != NULL)
		return (rv);
	rv = first_word_has_no_quotes(may_have_quotes);
	if (rv != NULL)
		return (rv);
	write(1, "No memory to allocate our args and exe names!", 46);
	return (NULL);
}

char	*ft_trim_right(char *totrim)
{
	int	i;

	i = 0;
	while (totrim[i] != '\0')
		i++;
	if (i > 0)
		i--;
	while (ft_isspace(totrim[i]))
	{
		totrim[i] = '\0';
		i--;
	}
	return (totrim);
}
