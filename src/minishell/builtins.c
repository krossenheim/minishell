/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtins.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwang <diwang@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 14:21:31 by diwang        #+#    #+#                 */
/*   Updated: 2024/06/04 12:12:46 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		j;
	int		l;

	j = 0;
	l = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	copy = (void *)malloc(l + 1);
	if (copy == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		copy[j] = s[j];
		j++;
	}
	copy[j] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = (char *)malloc(len + 1);
	if (subs == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

int	word_c(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (count);
}

int	ft_fr(char **tstr)
{
	int	i;

	i = 0;
	while (tstr && tstr[i] != NULL)
	{
		free(tstr[i]);
		i++;
	}
	free(tstr);
	return (0);
}

char	**tstr_all(char **tstr, const char *s, char c, int len)
{
	int		i;
	int		j;
	int		l;

	i = 0;
	l = 0;
	while (l < len)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j > 0)
		{
			tstr[l] = ft_substr(s, i, j);
			if (tstr[l] == NULL)
				return (ft_fr(tstr), NULL);
		}
		l++;
		i = i + j;
	}
	tstr[l] = NULL;
	return (tstr);
}

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





// int main()
// {
// 	char *ptr;

// 	while (ptr)
// 	{
// 		ptr = readline(STDIN_FILENO);
// 		printf("%s\n", ptr);
// 	}
// 	return (0);
// }


//cc builtins.c -lreadline -lncurses

//ptr = readline("enter some text: ");
//printf("%s\n", ptr);

//from scratch, write code for echo/export/unset/cd/pwd/env/exit

//echo
//if you type echo into the shell, as a prompt, display a line of text

// use readline ? b/c i want to return everything after "echo"


// int	echo_from_scratch(char **str)
// {
// 	char *ptr;
// 	char *using_echo;

// 	if (using_echo)
// 	{
// 		str = ft_split()
// 	}

