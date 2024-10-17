/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 14:21:31 by diwang        #+#    #+#                 */
/*   Updated: 2024/10/17 20:21:39 by diwang        ########   odam.nl         */
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

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
		i++;
	if (nptr[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * neg);
}
