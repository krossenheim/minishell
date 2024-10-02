/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:57:48 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/27 11:39:42 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *space_readline(char *prompt)
{
	char 	*line;
	char 	*tmp;

	tmp = readline(prompt);
	if (tmp == NULL)	
		return (NULL);
	while (tmp && ft_isspace(*tmp))
		tmp++;
	if (*tmp == '\0')
		return ("");
	add_history(tmp);
	line = space_separators(tmp);
	if (!line)
		return (NULL);
	free(tmp);
	return (line);
}
int	main_loop(t_mini *mini)
{
	while (1)
	{
		mini->spaced_input = space_readline(PROMPTLINE);
		if (mini->spaced_input == NULL)
			break; 
		if ((*mini->spaced_input == '\0')
		|| !quotes_matched(mini->spaced_input) 
		|| !early_syntax_check(mini->spaced_input) )
			continue ;
		parse_input_bla(mini);
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
	init_mini(&mini, envp);
	bind_signals();
	disable_echo_ctrl_chrcts();
	return_value = main_loop(&mini);
	ft_clean_exit(&mini);
	return (return_value);
}
