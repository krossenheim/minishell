/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs2.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/17 20:22:20 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	program_env(t_mini *mini)
{
	t_list	*tmp;

	tmp = mini->envp;
	while (tmp != NULL)
	{
		printf("%s\n", (char *) tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

int	program_pwd(void)
{
	char	buffer[1000];
	char	*buf;

	buf = getcwd(buffer, 1000);
	if (buf == NULL)
	{
		free(buf);
		return (1);
	}
	printf("%s\n", buffer);
	return (0);
}

int	program_exit(t_mini mini, t_hell *node)
{
	char	**args;

	args = node->args;
	if (node->argc == 2)
		mini.last_exit_code = ft_atoi(args[1]) % 256;
	clear_last_command(&mini);
	ft_clean_exit(&mini);
	exit(mini.last_exit_code);
}
