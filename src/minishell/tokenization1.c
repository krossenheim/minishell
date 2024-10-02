/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:36:35 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/26 20:52:07 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_sep(char c)
{
	char	*seps;

	seps = "<>;|";
	while (*seps != '\0')
	{
		if (c == *seps)
			return (true);
		seps++;
	}
	return (false);
}

static void	_space_separators(char *rv, char *src, int *i, int *j)
{
	if (src[(*i)] == '\\')
	{
		rv[(*j)++] = src[(*i)++];
		rv[(*j)++] = src[(*i)++];
	}
	else if (in_q((char *) src, (*i)) == 0 && is_sep(src[(*i)]))
	{
		rv[(*j)++] = ' ';
		if (src[(*i) + 1] && src[(*i) + 1] == src[(*i)])
			rv[(*j)++] = src[(*i)++];
		rv[(*j)++] = src[(*i)++];
		rv[(*j)++] = ' ';
	}
	else
		rv[(*j)++] = src[(*i)++];
}

char	*space_separators(char *src)
{
	char	*rv;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_skip_spaces(src, &i);
	rv = malloc(sizeof(char) * (ft_strlen(src) * 2));
	if (!rv)
		return (NULL);
	while (src[i] != '\0')
		_space_separators(rv, src, &i, &j);
	rv[j++] = '\0';
	return (rv);
}

void	ft_skip_spaces(char *line, int *i)
{
	while (ft_isspace(line[*i]))
		(*i)++;
}
