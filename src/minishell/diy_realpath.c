/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   diy_realpath.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 00:14:42 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/10 00:18:39 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_path_token(char *from, char *to)
{
	if (!from || !to)
		return (0);
	if (to - from == 2 && ft_strncmp(from, "..", 2) == 0)
		return (1);
	if (to - from == 1 && *from == '.')
		return (2);
	if (to - from == 1 && *from == '~')
		return (3);
	return (0);
}

char	*new_start_path(int	op_type)
{
	if (op_type == 1)
		return (ft_strdup(""));
	if (op_type == 2)
		return (ft_strdup(""));
	if (op_type == 3)
		return (ft_strdup(""));

}
bool traverse(char *start_path, char *instructions)
{
	// ls ././.././././minishell/src/././/////
	char	*ptr;
	char	*ptr1;

	ptr = instructions;
	while (*ptr == '/')
		ptr++;
	ptr1 = ptr + 1;
	while (*ptr1 != '\0' && *ptr1 != '/')
		ptr1++;
	if (is_valid_path_token(ptr, ptr1) > 0)
		return (-1);
	
	return (traverse(ptr1, ptr1))
}