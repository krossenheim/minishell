/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 13:45:50 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 12:41:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*lastnode;

	if (lst == NULL)
		return (NULL);
	lastnode = lst;
	while (lastnode->next != NULL)
		lastnode = lastnode->next;
	return (lastnode);
}
