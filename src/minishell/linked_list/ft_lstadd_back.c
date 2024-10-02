/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 13:46:20 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 12:41:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	new->prev = temp;
}
