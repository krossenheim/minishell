/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/12 13:46:02 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/13 12:41:41 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	free(lst);
	lst = NULL;
}
