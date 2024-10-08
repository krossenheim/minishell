/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs4.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/08 21:24:01 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_head(t_mini *mini)
{
	mini->envp = mini->envp->next;
	free(mini->envp->prev->content);
	free(mini->envp->prev);
}

static void	unset_middle(t_list	**var_node)
{
	(*var_node)->prev->next = (*var_node)->next;
	(*var_node)->next->prev = (*var_node)->prev;
	free((*var_node)->content);
	free(*var_node);
}

static void	unset_tail(t_list	**var_node, t_list *head)
{
	*var_node = ft_lstlast(head);
	(*var_node)->prev->next = NULL;
	free((*var_node)->content);
	free(*var_node);
}

int	program_unset(t_hell *exec_info, t_mini *mini)
{
	t_list	*head;
	t_list	*var_node;

	if (exec_info->argc < 2)
		return (0);
	var_node = get_env_node(exec_info->args[1], *mini);
	if (var_node == NULL)
		return (1);
	head = mini->envp;
	if (head == var_node)
		unset_head(mini);
	else if (ft_lstlast(head) == var_node)
		unset_tail(&var_node, head);
	else
		unset_middle(&var_node);
	return (0);
}
