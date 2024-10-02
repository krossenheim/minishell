/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lst_connectnodes.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/20 13:11:05 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 12:41:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lst_connect_nodes(t_list	*node_left,	t_list *node_right)
{
	if (!node_left || !node_right)
		return ;
	node_left->next = node_right;
	node_right->prev = node_left;
	if (node_left->prev == NULL)
		node_left->prev = node_right;
	if (node_right->next == NULL)
		node_right->next = node_left;
}
