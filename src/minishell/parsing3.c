/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing3.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/11 11:00:45 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*not_first_word(char *mb_hasq)
{
	char	*tmp;
	int		quote_met;

	quote_met = -1;
	tmp = mb_hasq;
	while (ft_isspace(*tmp))
		tmp++;
	while (*tmp != '\0')
	{
		if (ft_isspace(*tmp) && quote_met == -1)
			break ;
		if (is_quote(*tmp) && quote_met == -1)
			quote_met = tmp - mb_hasq;
		else if (is_quote(*tmp) && quote_met != -1
			&& mb_hasq[quote_met] == *tmp)
			break ;
		tmp++;
	}
	if (is_quote(*tmp))
		tmp++;
	while (ft_isspace(*tmp))
		tmp++;
	return (ft_trim_right(ft_strdup(tmp)));
}

bool	is_actual_separator(t_tkn_dlist node)
{
	if (is_sep(*node.contents) && !node.quoted)
		return (true);
	return (false);
}

int	parse_tokenize_execute(t_mini *mini)
{
	if (tokenize_input(mini, (char *) mini->spaced_input) != 1)
		return (1);
	if (!check_tokens_syntax(mini->input_tknized))
		return (1);
	if (has_wildcards(mini->input_tknized))
		autocomplete(mini);
	if (fill_structs(mini) != 1)
		return (1);
	if (execution(mini) != 1)
		return (1);
	return (0);
}
