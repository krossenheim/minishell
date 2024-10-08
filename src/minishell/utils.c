/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 12:12:26 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 12:20:04 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;

	i = 0;
	while (s[i] != '\0' || (char) c == '\0')
	{
		if ((char) s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strncmp(const char *s1_ptr, const char *s2_ptr, size_t n)
{
	size_t			i;

	if (!s1_ptr || !s2_ptr)
		return (0);
	i = 0;
	while (s1_ptr[i] != '\0' || s2_ptr[i] != '\0')
	{
		if (i >= n)
			break ;
		if (s1_ptr[i] != s2_ptr[i])
			return ((unsigned char) s1_ptr[i] - (unsigned char) s2_ptr[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

bool	ft_isspace(char c)
{
	if (c == '\0')
		return (false);
	return (c <= 32);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	int		size;
	char	*concatenated;
	int		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	size = s1_len + s2_len + 1;
	concatenated = malloc(size * sizeof(char));
	if (concatenated == NULL)
		return (concatenated);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			concatenated[i] = s1[i];
		else
			concatenated[i] = s2[i - s1_len];
		i++;
	}
	concatenated[i] = '\0';
	return (concatenated);
}
