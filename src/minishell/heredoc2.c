/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc2.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 10:19:51 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 23:23:22 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	keep_questionmark(int *i, int dest, t_mini mini)
{
	char	*strval;

	strval = ft_itoa(mini.last_exit_code);
	write(dest, strval, ft_strlen(strval));
	free(strval);
	(*i) += 2;
}

void	handle_dollar(char *str, int *i, int dest, t_mini mini)
{
	char	*tmp;
	char	*tmp1;

	tmp = str + (*i + 1);
	if (*tmp == '?')
		return (keep_questionmark(i, dest, mini));
	while (isalnum(*tmp) || *tmp == '_')
		tmp++;
	tmp--;
	tmp1 = ft_substr(str + *i + 1, 0, tmp - (str + *i));
	if (!tmp1)
		return ;
	if (get_env_var(tmp1, mini) != NULL)
	{
		write(dest,
			get_env_var(tmp1, mini),
			ft_strlen(get_env_var(tmp1, mini)));
	}
	(*i) += (ft_strlen(tmp1) + 1);
	free(tmp1);
}

void	expanded_vars(char *raw, int fd, t_mini mini)
{
	int		i;

	i = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '$' && raw[i + 1] != '\0' && raw[i + 1] != ' ')
			handle_dollar(raw, &i, fd, mini);
		else
			write(fd, raw + i++, 1);
	}
	write(fd, "\n", 1);
}
