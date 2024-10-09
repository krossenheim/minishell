/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/03 11:55:22 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/10/09 14:56:48 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ECHOCTL 0001000
# define PROMPTLINE "\e[1;92mMinishell:\e[0m"
# define TEMP_HEREDOC ".temp_heredoc"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <signal.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h> 
# include <sys/wait.h>
# include "limits.h"
# include "termios.h"
# include <dirent.h>
# include <sys/stat.h>

typedef struct s_ll
{
	struct s_ll			*next;
	struct s_ll			*prev;
	void				*content;
}	t_list;

typedef struct s_match_info
{
	char	*name;
	bool	isdir;
	bool	is_match;
}	t_match_info;

t_list		*ft_lstnew(void *contnet);
void		ft_lstadd_front(t_list **lst, t_list *newnode);
int			ft_lstsize(t_list *list);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newnode);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list *lst, void (*del)(void*));
void		ft_lst_connect_nodes(t_list	*node_left,	t_list *node_right);
void		ft_lst_close(t_list **lst);
void		ft_lst_open(t_list **lst);

typedef struct s_tkn_dlist
{
	struct s_tkn_dlist	*next;
	struct s_tkn_dlist	*prev;
	char				*contents;
	bool				is_sep;
	bool				quoted;
	unsigned int		type;

}	t_tkn_dlist;

typedef struct t_hell
{
	char				**args;
	int					argc;
	char				*path;
	int					pipe;
	int					infile;
	int					outfile;
	t_tkn_dlist			*firstoken;
	struct s_mini		*mini;
	struct t_hell		*next;
}	t_hell;

typedef struct s_mini
{
	char		*home;
	t_list		*envp;
	t_tkn_dlist	*input_tknized;
	t_hell		*to_exec;
	char		*spaced_input;
	int			last_exit_code;
	int			saved_stdin;
	int			saved_stdout;
	pid_t		last_pid;

}	t_mini;

//Wildcard
void		autocomplete(t_mini *mini);

//Wildcard1
t_list		*fetch_dir_contents(DIR	*folder, char *to_match);

// Wildcard2
bool		replace_and_insert(t_tkn_dlist *tmp, char **replaced);
bool		wildcard2_replace(t_tkn_dlist *to_replace, char **replaced);
bool		wildcard2_insert(t_tkn_dlist *to_replace,
				char **replaced,
				t_tkn_dlist *to_insert,
				int lstsize);

//Programs1
int			program_env(t_mini *mini);
int			program_pwd(void);
int			program_unset(t_hell *exe, t_mini *mini);
void		no_program(char *exe_name);
int			program_echo(t_hell *to_exec);
int			program_cd(t_mini *mini, t_hell *cur);
int			program_exit(t_mini mini);
int			program_export(char **args, t_mini *mini);

//Env vars
t_list		*envp_to_linked_list(char **envp);
char		*get_env_var(char *name, t_mini mini);
t_list		*get_env_node(char *name, t_mini mini);

// Disable echo ctrlcharacters
void		disable_echo_ctrl_chrcts(void);

//Teardown
int			free_split(char **split);
void		clear_last_command(t_mini *mini);

// Quotes
bool		is_quote(char c);
bool		quotes_matched(char *str);

//Utils
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
bool		ft_isspace(char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_isalpha(int n);

// Signal_handler
void		bind_signals(void);
void		handle_ctrl_c(int n);

// ft_itoa
char		*ft_itoa(int n);

// ft_memcpy
void		*ft_memcpy(void *dest, const void *src, size_t n);

// Builtins
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			word_c(const char *s, char c);
int			ft_fr(char **tstr);
char		**tstr_all(char **tstr, const char *s, char c, int len);
char		**ft_split(char const *s, char c);

// ft_clean_exit
void		ft_clean_exit(t_mini *mini);

// Heredoc 
void		keep_questionmark(int *i, int dest, t_mini mini);
void		handle_dollar(char *str, int *i, int dest, t_mini mini);
void		expanded_vars(char *raw, int fd, t_mini mini);

//Heredoc 2
bool		heredoc(char *marker, t_mini *mini);
void		clear_tempfile(void);

// Initialization
void		init_mini(t_mini *mini, char **envp);
int			fill_structs(t_mini *mini);
char		**envp_get(t_mini *mini);

// Tokenization
t_tkn_dlist	*get_sep_r(t_tkn_dlist *current);
int			tokenize_input(t_mini *mini, char *spaced_line);

// Tokenization1
bool		is_sep(char c);
char		*space_separators(char *src);
void		ft_skip_spaces(char *line, int *i);

// Tokenization2
int			in_q(char *str, int index);
t_hell		*init_new_summary(t_tkn_dlist *current);

// Tokenization_calc
int			calculate_expanded_len(char *str, t_mini *mini);

// Tokenization_write
void		write_tkn(char *str, int *i, t_tkn_dlist *unfinished, t_mini mini);

//Execution
bool		set_infile(t_hell *dest, t_tkn_dlist *current);
bool		set_outfile(t_hell *dest, t_tkn_dlist *current);
int			execution(t_mini *mini);
void		set_full_path(t_hell *head, t_mini *mini);
void		ft_waitloop(void);

//Execution1
int			is_builtin(t_hell *cur);
int			exec_builtin(t_hell *head, t_mini *mini);
void		ft_pipe(t_hell *head, t_mini *mini, int fd[2]);
void		ft_bite_size_write(int fd[2]);
int			ft_pid(pid_t pid);

//Execution2
void		ft_parent(t_hell *head, int fd[2], int *prev_fd);
void		ft_execution_helper(t_mini *mini, t_hell *head);
void		ft_execution_helper2(t_mini *mini, t_hell *head);
void		ft_execution_helper3(t_mini *mini);
int			execution(t_mini *mini);

//Execution3
int			ft_is_not_builtin(t_hell *head, t_mini *mini,
				int fd[2], int *prev_fd);
int			ft_newbi(t_hell *head, t_mini *mini, int fd[2], int *prev_fd);
void		ft_redirecs(t_hell *head);
void		ft_close_in_out(t_mini *mini);
void		ft_close_redirecs(t_hell *head);
void		ft_set_in_out(t_mini *mini);

//Parsing1
void		add_last(t_mini *mini, t_hell *to_add);
bool		early_syntax_check(char *input);
bool		has_wildcards(t_tkn_dlist *head);
bool		check_tokens_syntax(t_tkn_dlist *h);

//Parsing2
char		*first_word_has_no_quotes(char *has_no_quotes);
char		*first_word_is_quoted(char *may_have_quotes);
char		*first_word(char *may_have_quotes);
char		*ft_trim_right(char *totrim);

//Parsing3
char		*not_first_word(char *may_have_quotes);
bool		is_actual_separator(t_tkn_dlist node);
int			parse_tokenize_execute(t_mini *mini);

// Builtin programs 3b
char		*get_pwd(t_mini *mini);
void		update_old_pwd(char **args, t_mini *mini);
void		update_pwd(char **args, t_mini *mini, char *path);
char		*get_cd_path(t_list *envp_list);
void		ft_for_home_cd(char **args, t_mini *mini);

// Infileoutfine
bool		set_infile(t_hell *dest, t_tkn_dlist *current);
bool		set_outfile(t_hell *dest, t_tkn_dlist *current);
#endif
