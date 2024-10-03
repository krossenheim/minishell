/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization_calc.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 15:38:55 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:08:10 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	expanded_var_offset(char *varname, t_mini mini)
{
	if (get_env_var(varname, mini) == NULL)
		return (-(ft_strlen(varname) + 1));
	return (ft_strlen(get_env_var(varname, mini)) - (ft_strlen(varname) + 1));
}

static int	_calc_questionmark(int *i, t_mini *mini)
{
	char	*strval;
	int		len_needed;

	strval = ft_itoa(mini->last_exit_code);
	len_needed = ft_strlen(strval);
	free(strval);
	(*i) += 2;
	return (len_needed + 1);
}

static void	_calculate_expanded_len(char *str, int *i, int *j, t_mini *mini)
{
	char	*tmp;
	int		offset_calc;

	tmp = str + *i + 1;
	if (*tmp == '?')
	{
		*j += _calc_questionmark(i, mini);
		return ;
	}
	while (isalnum(*tmp) || *tmp == '_')
		tmp++;
	tmp--;
	if (!tmp)
		write(1, "this should never happen as the input was validated", 52);
	tmp = ft_substr(str + *i + 1, 0, tmp - (str + *i));
	offset_calc = expanded_var_offset(tmp, *mini);
	if (offset_calc > 0)
		*j += expanded_var_offset(tmp, *mini);
	*i += ft_strlen(tmp) + 1;
	free(tmp);
}

static void	_calc_deal_with_escaped(char *str, int *i, int *j)
{
	char	escaped;

	if (!str || str[*i] != '\\' || !str[(*i) + 1] || in_q(str, *i) == 2)
		return ;
	escaped = str[(*i) + 1];
	if (escaped == '\\' || is_quote(escaped))
		(*j)++;
	else
	{
		if (in_q(str, *i) == 1)
			(*j)++;
		(*j)++;
	}
	(*i) += 2;
}

int	calculate_expanded_len(char *str, t_mini *mini)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0' && (in_q(str, i) != 0 || !ft_isspace(str[i])))
	{
		if (in_q(str, i) == 2)
		{
			i++;
			j++;
		}
		else if (is_quote(str[i]) && in_q(str, i) == 0)
			i++;
		else if (in_q(str, i) < 2 && str[i] == '$' && str[i + 1] != '\0')
			_calculate_expanded_len(str, &i, &j, mini);
		else if (str[i] == '\\')
			_calc_deal_with_escaped(str, &i, &j);
		else
		{
			i++;
			j++;
		}
	}
	return (j);
}
