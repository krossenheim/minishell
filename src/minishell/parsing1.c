/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing1.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:42:53 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 22:25:45 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool check_double_pipes(char *input)
{
	int i;

	i = 0;
	while (input[i] != '\0')
	{
		while (in_q(input, i) != 0)
			i++;
		if (input[i] == '\\')
			{
				i+=2;
			}
		if (input[i] == '|' && input[i + 1] && input[i + 1] == '|')
			return (false);
		i++;
	}
	return (true);
}

bool early_syntax_check(char *input)
{
	bool	rv;
	int		len;

	rv = true;
	len = ft_strlen(input);
	if (rv && len >= 1 && (is_sep(*input) || ft_isspace(*input)))
		rv = (false);
	if (rv && !check_double_pipes(input))
		rv = false;
	if (!rv)
		printf("Syntax error;\n");
	return (rv);
}


void	add_last(t_mini *mini, t_hell *to_add)
{
	t_hell *tmp;

	if (!mini || !to_add)
		return ;
	to_add->mini = mini;
	if (mini->to_exec == NULL)
	{
		mini->to_exec = to_add;
		return ;
	}
	tmp = mini->to_exec;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = to_add;
}

static bool	has_wildcards(t_tkn_dlist *head)
{
	if (!head || !head->next)
		return (false);
	head = head->next;
	while (head)
	{
		if (!head->quoted && ft_strchr(head->contents, '*') != NULL)
			return (true);
		head = head->next;
	}
	return (false);
}

bool	is_actual_separator(t_tkn_dlist node)
{
	if (is_sep(*node.contents) && !node.quoted)
		return (true);
	return (false);
}

bool	check_tokens_syntax(t_tkn_dlist *head)
{
	while (head)
	{
		if (is_actual_separator(*head))
		{
			if (head->next == NULL)
			{
				printf("syntax error to the right of token '%s'\n", head->contents);
				return (false);
			}
			if (is_actual_separator(*head->next) 
			&& head->next->contents != head->contents 
			&& (-('>' - '<') != *head->contents - *head->next->contents ||
				 (ft_strlen(head->contents) + ft_strlen(head->next->contents)) != 2))
			{
				printf("syntax error near unexpected token '%s'\n", head->next->contents);
				return (false);
			}
		}
		head = head->next;
	}
	return (true);
}

int	parse_input_bla(t_mini *mini)
{
	if (tokenize_input(mini, (char *) mini->spaced_input) != 1)
		return (-1);
	if (!check_tokens_syntax(mini->input_tknized))
		return (-1);
	if (has_wildcards(mini->input_tknized))
		autocomplete(mini);
	if (fill_structs(mini) != 1)
		return (-2);
	execution(mini);
	return (1);
}

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
