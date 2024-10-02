/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quotes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 12:22:46 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/17 12:50:03 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	even_number_of_quotes(char *str)
{
	int		singles;
	int		doubles;
	int		i;

	i = 0;
	if (!str)
		return (false);
	singles = 0;
	doubles = 0;
	while (str[i] != '\0')
	{
		while (str[i] == '\\' && in_q(str, i) != 2)
			i+=2;
		if (str[i] == '\'' && doubles % 2 == 0)
			singles++;
		if (str[i] == '\"' && singles % 2 == 0)
			doubles++;
		i++;
	}
	if ((singles % 2 != 0 && str[i] != '\'') || (doubles % 2 != 0 && str[i] != '\"'))
		return (false);
	return (true);
}

bool	is_quote(char c)
{
	if (c == '\'')
		return (true);
	if (c == '\"')
		return (true);
	return (false);
}

static char	get_oppoquote(char quote)
{
	if (quote == '\"')
		return ('\'');
	if (quote == '\'')
		return ('\"');
	return ('\0');
}

static bool	find_matching_quote(char *str, char quote)
{
	int		i;
	char	oppoquote;
	int		oppocount;

	oppoquote = get_oppoquote(quote);
	i = ft_strlen(str);
	oppocount = 0;
	while (i > 0)
	{
		while (str[i] == '\\' && in_q(str, i) != 2)
			i+=2;
		if (str[i] == oppoquote)
			oppocount++;
		if (str[i] == quote && oppocount % 2 == 0)
			return (true);
		i--;
	}
	return (false);
}

bool	quotes_matched(char *str)
{
	bool	rv;

	rv = true;
	if (!str || !even_number_of_quotes(str))
		rv = false;
	if (rv && is_quote(*str) == true && find_matching_quote(str, *str) != true)
		rv = false;
	if (!rv)
		printf("Syntax error, mismatched quotes\n");
	return (rv);
}
