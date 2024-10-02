/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   signal_handlers.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/05 14:41:48 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/26 17:15:49 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_ctrl_c()
{
	write(1, "\n" , 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	bind_signals(void)
{
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
}

