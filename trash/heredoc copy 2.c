/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   heredoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 10:19:51 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/27 00:28:38 by jose-lop      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int killsig;

static void  _keep_questionmark(int *i, int dest, t_mini mini)
{
	char *strval;

	strval = ft_itoa(mini.last_exit_code);
	write(dest, strval, ft_strlen(strval));
	free(strval);
	(*i) += 2;
}

static void _handle_dollar(char *str, int *i, int dest, t_mini mini)
{
	char	*tmp;
	char	*tmp1;

	tmp = str + (*i + 1);
	if (*tmp == '?')
		return (_keep_questionmark(i, dest, mini));
	while (isalnum(*tmp) || *tmp == '_')
		tmp++;
	tmp--;
	tmp1 = ft_substr(str + *i + 1, 0, tmp - (str + *i));
	if (!tmp1)
		return ;
	if (get_env_var(tmp1, mini) != NULL)
	{
		write(dest,
			get_env_var(tmp1, mini) + ft_strlen(tmp1) + 1,
			ft_strlen(get_env_var(tmp1, mini)) - (ft_strlen(tmp1) + 1));
	}
	(*i) += (ft_strlen(tmp1) + 1);
	free(tmp1);
}

static void	expanded_vars(char *raw, int fd, t_mini mini)
{
	int		i;
	
	i = 0;
	while (raw[i] != '\0')
	{
		if (raw[i] == '$')
			_handle_dollar(raw, &i, fd, mini);
		else
			write(fd, raw + i++, 1);
	}
	write(fd, "\n", 1);
}

void	killdoc()
{
	killsig = 1;
	handle_ctrl_c();
}

// void	child_process()
// {
	
// }
bool	heredoc(char *marker, t_mini *mini)
{
	char	*line;
	int		fd;
	
	signal(SIGQUIT, SIG_DFL);
	killsig = 0;
	signal(SIGINT, killdoc);
	fd = open(TEMP_HEREDOC, O_RDWR | O_CREAT | O_APPEND, 0666);
	while (killsig == 0)
	{
		line = readline("> ");
		if (ft_strncmp(marker, line, INT_MAX) == 0)
		{
			free(line);
			break ;
		}
		expanded_vars(line, fd, *mini);
		free(line);
	}
	signal(SIGINT, handle_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	close(fd);
	return (!killsig);
}