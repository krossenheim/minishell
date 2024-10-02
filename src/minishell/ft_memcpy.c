/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 14:05:03 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/08/27 12:19:57 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_p;
	unsigned char	*src_p;

	src_p = (unsigned char *)src;
	dest_p = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	i = 0;
	while (n > i)
	{
		dest_p[i] = src_p[i];
		i++;
	}
	return (dest);
}
