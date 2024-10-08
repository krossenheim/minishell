/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 14:21:31 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/08 21:40:51 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_split(char const *s, char c)
{
	char	**tstr;
	int		len;

	if (s == NULL)
		return (NULL);
	len = word_c(s, c);
	tstr = malloc((len + 1) * sizeof(char *));
	if (tstr == NULL)
		return (NULL);
	return (tstr_all(tstr, s, c, len));
}


int	ft_isalpha(int n)
{
	return ((n >= 97 && n <= 122) || (n >= 65 && n <= 90));
}