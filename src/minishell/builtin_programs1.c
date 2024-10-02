/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs1.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/07 12:31:41 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/26 14:48:14 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


//write(mini->to_exec->outfile, (char *) tmp->content, ft_strlen((char *) tmp->content))
void	program_env(t_mini *mini)
{
	t_list *tmp;

	tmp = mini->envp;

	while (tmp != NULL)
	{
		printf("%s\n", (char *) tmp->content);
		tmp = tmp->next;
	}
}

void	program_pwd()
{
	char buffer[1000];
	char *buf;
	
	buf = getcwd(buffer, 1000);
	if (buf == NULL)
	{
		free(buf);
		return ;
	}
	printf("%s\n", buffer);
}

//mkdir
//my cd function doesn't work with valgrind

void program_unset(t_hell *exec_info, t_mini *mini)
{
	t_list	*head;
	t_list	*var_node;
	
	if (exec_info->argc < 2)
		return ;
	var_node = get_env_node(exec_info->args[1], *mini);
	if (var_node == NULL)
		return ;
	head = mini->envp;

	if (head == var_node) // remove head 
	{
		mini->envp = mini->envp->next;
		free(mini->envp->prev->content);
		free(mini->envp->prev);
	}
	else if (ft_lstlast(head) == var_node) // removet ail
	{
		var_node = ft_lstlast(head);
		var_node->prev->next = NULL;
		free(var_node->content); //!!
		free(var_node); //!!
	}
	else
	{
		var_node->prev->next = var_node->next;
		var_node->next->prev = var_node->prev;
		free(var_node->content); //!!
		free(var_node);
	}
}

 
static bool has_newline(t_hell *to_exec, int *i)
{
	char *tmp;
	tmp = to_exec->args[*i];
	
	if (to_exec->argc <= 1)
		return (false) ;
	if (ft_strncmp(to_exec->args[*i], "-n", 2) == 0) 
	{
		tmp = tmp + 2;
		while (*tmp)
		{
			if (*tmp != 'n')
				return (false);
			tmp++;
		}
		return (true);
	}
	return (false);
}

void	program_echo(t_hell *to_exec)
{
	int		i;
	bool	newline;
	int		j;

	i = 1;
	newline = true;
	if (has_newline(to_exec, &i))
	{
		i++;
		newline = false;
	}
	while (to_exec->argc > i)
	{
		j = 0;
		while (to_exec->args[i][j])
		{
			write(1, &to_exec->args[i][j], 1);
			j++;
		}
		if (to_exec->args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (newline)
		write(1, "\n", 1);
}

// void	program_echo_no_option(t_mini *mini)
// {
// 	int	i;
// 	char **args;
// 	args = mini->to_exec->args;

// 	i = 1;
	
// 	while (args && args[i])
// 	{
// 		printf("%s", args[i]);
// 		if (args[i + 1])
// 			printf(" ");
// 		else
// 			printf("\n");
// 		i++;
// 	}
// }

// void	program_echo(t_mini *mini)
// {
// 	int	i;
// 	char **args;
// 	args = mini->to_exec->args;

// 	i = 1;

// 	if (ft_strncmp(args[1], "-n", 2) == 0) 
// 	{
// 		while (args && args[i])
// 		{
// 			printf("%s", args[i + 1]);
// 			if (args[i + 1])
// 				printf(" ");
// 			i++;
// 		}
// 	}
// 	else
// 		program_echo_no_option(mini);
// }


// void	program_echo(char *exe_args)
// {
// 	char	*_first_word;
// 	char	*_notfirstword;
// 	bool	donewline;

// 	donewline = true;
// 	_first_word = first_word(exe_args);
// 	if (_first_word != NULL)
// 	{
// 		if (ft_strncmp("-n", _first_word, 3) == 0)
// 			donewline = false;
// 	}
// 	_notfirstword = not_first_word(exe_args);
// 	if (ft_strlen(_notfirstword) == 0 && _first_word != NULL)
// 		write(1, _first_word, ft_strlen(_first_word));
// 	else if (ft_strlen(_notfirstword) > 0)
// 		write(1, _notfirstword, ft_strlen(_notfirstword));
// 	if (_notfirstword != NULL)
// 		free(_notfirstword);
// 	if (_first_word != NULL)
// 		free(_first_word);
// 	if (donewline)
// 		write(1, "\n", 1);
// 	rl_on_new_line();
// 	rl_replace_line("", 0);
// }

void no_program(char *exe_name)
{
	printf("command not found: %s\n", exe_name);
	return ; 
}