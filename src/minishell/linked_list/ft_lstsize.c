/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 13:45:33 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 12:41:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lstsize(t_list *list)
{
	int		rv;
	t_list	*node;

	if (list == NULL)
		return (0);
	rv = 0;
	node = list;
	while (node != NULL)
	{
		node = node->next;
		rv++;
	}
	return (rv);
}
