/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disable_echo_ctrl.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:28:48 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/06/07 12:29:22 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	disable_echo_ctrl_chrcts()
{
	struct termios term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, 0, &term);
}
