/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenization3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:40:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/15 14:47:53 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	should_replace_squiggle(int *i, char *s)
{
	bool	rv;

	rv = ((!(*i) || (*i > 0 && s[*i - 1] == ' '))
			&& in_q(s, *i) == 0 && s[*i] == '~');
	return (rv);
}

int	_w_home_dir(int *i, char *dest, t_mini *mini)
{
	int	written;

	written = ft_strlen(mini->home);
	ft_memcpy(dest, mini->home, ft_strlen(mini->home));
	(*i)++;
	return (written);
}

bool	should_expand_dollarvar(char *s, int i)
{
	bool	rv;

	rv = (in_q(s, i) < 2 && s[i] == '$'
			&& s[i + 1] && s[i + 1] != ' ' && in_q(s, i) == in_q(s, i + 1));
	return (rv);
}

void	_calc_home_dir_len(int *i, int *j, t_mini *mini)
{
	(*j) += ft_strlen(mini->home);
	(*i)++;
}

void	increase_both(int *a, int *b)
{
	(*a)++;
	(*b)++;
}
