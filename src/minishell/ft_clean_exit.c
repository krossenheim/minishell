/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_clean_exit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 10:55:21 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/26 22:24:17 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void clean_envp_ll(t_mini *mini)
{
	t_list	*list;
	t_list	*tmp;

	if (!mini)
		return ;
	list = mini->envp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
}

void ft_clean_exit(t_mini *mini)
{
	// remove(TEMP_HEREDOC);
	clean_envp_ll(mini);
	rl_clear_history();
	printf("Leaving %sPID%d\n", PROMPTLINE, getpid());
}