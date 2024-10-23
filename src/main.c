/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:57:48 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/23 16:12:51 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*space_readline(char *prompt)
{
	char	*line;
	char	*tmp;
	char	*freeme;

	tmp = readline(prompt);
	freeme = tmp;
	if (tmp == NULL)
		return (NULL);
	while (tmp && ft_isspace(*tmp))
		tmp++;
	if (*tmp == '\0')
	{
		free(freeme);
		return ("");
	}
	add_history(tmp);
	line = space_separators(tmp);
	if (!line)
	{
		free(freeme);
		return (NULL);
	}
	free(freeme);
	return (line);
}

int	main_loop(t_mini *mini)
{
	while (1)
	{
		bind_signals();
		mini->spaced_input = space_readline(PROMPTLINE);
		default_binds();
		if (mini->spaced_input == NULL)
			break ;
		if ((*mini->spaced_input == '\0')
			|| !quotes_matched(mini->spaced_input)
			|| !early_syntax_check(mini->spaced_input))
			continue ;
		if (parse_tokenize_execute(mini) != 0)
			mini->last_exit_code = 1;
		clear_last_command(mini);
	}
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	mini;
	int		return_value;

	if (argc != 1 || (0 && argv))
		printf("This program takes no arguments, they will be ignored.\n");
	if (!init_mini(&mini, envp))
	{
		printf("Failure initializing t_mini\n");
		return (3);
	}
	return_value = main_loop(&mini);
	ft_clean_exit(&mini);
	return (return_value);
}
