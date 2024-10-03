/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization_write.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 15:38:55 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:07:56 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	_keep_questionmark(int *i, char *dest, t_mini mini)
{
	char	*strval;
	int		ammount_written;

	if (!dest || !i)
		return (0);
	strval = ft_itoa(mini.last_exit_code);
	ammount_written = ft_strlen(strval);
	ft_memcpy(dest, strval, ammount_written);
	free(strval);
	(*i) += 2;
	return (ammount_written);
}

static int	_handle_dollar(char *str, int *i, char *dest, t_mini mini)
{
	char	*tmp;
	char	*tmp1;
	int		written;

	written = 0;
	tmp = str + (*i + 1);
	if (*tmp == '?')
		return (_keep_questionmark(i, dest, mini));
	while (isalnum(*tmp) || *tmp == '_')
		tmp++;
	tmp--;
	tmp1 = ft_substr(str + *i + 1, 0, tmp - (str + *i));
	if (!tmp1)
		write(1, "this should never happen as the input was validated", 52);
	if (get_env_var(tmp1, mini) != NULL)
	{
		ft_memcpy(dest,
			get_env_var(tmp1, mini) + ft_strlen(tmp1) + 1,
			ft_strlen(get_env_var(tmp1, mini)) - (ft_strlen(tmp1) + 1));
		written = ft_strlen(get_env_var(tmp1, mini)) - (ft_strlen(tmp1) + 1);
	}
	(*i) += (ft_strlen(tmp1) + 1);
	free(tmp1);
	return (written);
}

static int	_w_handle_escaped(char *str, int *i, char *dest, t_tkn_dlist *new)
{
	char	escaped;
	int		written;

	written = 0;
	if (!str || str[*i] != '\\' || !str[(*i) + 1] || in_q(str, *i) == 2)
		return (0);
	escaped = str[(*i) + 1];
	new->quoted = true;
	if (escaped == '\\' || is_quote(escaped))
		dest[written++] = escaped;
	else
	{
		if (in_q(str, *i) == 1)
			dest[written++] = '\\';
		dest[written++] = escaped;
	}
	*i += 2;
	return (written);
}

void	write_tkn(char *str, int *i, t_tkn_dlist *new, t_mini mini)
{
	int		j;

	j = 0;
	while (str[*i] != '\0' && (in_q(str, *i) > 0 || !ft_isspace(str[*i])))
	{
		if (in_q(str, *i) == 2)
			new->contents[j++] = str[(*i)++];
		else if (is_quote(str[*i]) && in_q(str, *i) == 0)
			(*i)++;
		else if (in_q(str, *i) < 2 && str[*i] == '$' && str[*i + 1] != '\0')
			j += _handle_dollar(str, i, new->contents + j, mini);
		else if (str[*i] == '\\')
			j += _w_handle_escaped(str, i, new->contents + j, new);
		else
			new->contents[j++] = str[(*i)++];
	}
	new->contents[j++] = '\0';
}
