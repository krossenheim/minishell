/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_remove_and_reconnect.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/13 12:55:58 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 13:05:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void del_contents(t_list *node)
{
	free(node->content);
}

t_list	*ft_lst_remove_and_reconnect(t_list *node)
{
	t_list	*new_ptr;

	if (node->prev == NULL && node->next == NULL)
	{
		ft_lstdelone(node, del_contents);
		free(node);
		return (NULL);
	}
	if (node->prev == NULL && node->next != NULL)
	{
		new_ptr = node->next;
		ft_lstdelone(node, del_contents);
		free(node);
		return (new_ptr);
	}
	if (node->prev != NULL && node->next != NULL)	
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
		ft_lstdelone(node, del_contents);
		free(node);
	}
}