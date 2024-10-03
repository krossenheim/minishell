/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   teardown.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 19:51:27 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/03 23:09:11 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_tokens(t_mini *mini)
{
	t_tkn_dlist	*tmp;
	t_tkn_dlist	*list;

	if (!mini && !mini->input_tknized)
		return ;
	list = mini->input_tknized;
	while (list->prev)
		list = list->prev;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->contents);
		free(tmp);
	}
	mini->input_tknized = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}

static void	clear_exec_struct(t_mini *mini)
{
	t_hell	*tmp;
	t_hell	*list;

	if (!mini || !mini->to_exec)
		return ;
	list = mini->to_exec;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->path);
		free_split(tmp->args);
		free(tmp);
	}
	mini->to_exec = NULL;
}

void	clear_last_command(t_mini *mini)
{
	clear_exec_struct(mini);
	clear_tokens(mini);
	remove(TEMP_HEREDOC);
	free(mini->spaced_input);
}
