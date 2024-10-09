/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/03 12:47:19 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 20:20:34 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_mini(t_mini *mini, char **envp)
{
	mini->envp = envp_to_linked_list(envp);
	mini->home = get_env_var("PWD=", *mini);
	mini->to_exec = NULL;
	mini->last_pid = -1;
	mini->input_tknized = NULL;
	mini->saved_stdout = dup(STDOUT_FILENO);
	mini->saved_stdin = dup(STDIN_FILENO);
	mini->last_exit_code = 0;
}

int	fill_structs(t_mini *mini)
{
	t_tkn_dlist	*tokens;
	t_hell		*new;
	t_tkn_dlist	*sepahead;

	tokens = mini->input_tknized;
	sepahead = NULL;
	while (tokens)
	{
		if (sepahead == NULL || *(sepahead->contents) == '|')
		{
			new = init_new_summary(tokens);
			set_full_path(new, mini);
			if (!new)
				return (-1);
			add_last(mini, new);
		}
		if (!(set_infile(new, tokens) && set_outfile(new, tokens)))
			return (-1);
		sepahead = get_sep_r(tokens);
		if (!sepahead)
			break ;
		tokens = sepahead->next;
	}
	return (1);
}

char	**envp_get(t_mini *mini)
{
	t_list	*cur;
	int		i;
	int		size;
	char	**envp;

	if (!mini)
		return (NULL);
	cur = mini->envp;
	size = ft_lstsize(cur);
	envp = malloc(sizeof(char *) * (size + 1));
	if (!envp)
		return (NULL);
	i = 0;
	while (cur)
	{
		envp[i++] = cur->content;
		cur = cur->next;
	}
	envp[i++] = NULL;
	return (envp);
}
