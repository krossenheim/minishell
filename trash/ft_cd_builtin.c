/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_cd_builtin.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/11 16:28:09 by jose-lop      #+#    #+#                 */
/*   Updated: 2024/09/26 18:01:12 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	program_export_2(char *var_newval, t_mini *mini) 
{
	t_list  *new;
	char    *tmp;
	t_list  *envp;

	new = NULL;
    tmp = var_newval;
	if (tmp == NULL || ft_strlen(tmp) == 0)
		return ;
	if (!(export_formatted(tmp)))
		return ;
	while (*tmp && *tmp != '=')
		tmp++;
	envp = mini->envp;
	while (envp)
	{
		if (ft_strncmp(envp->content, var_newval, tmp - var_newval + 1) == 0)
		{
			free(envp->content);
			envp->content = ft_strdup(var_newval);
			return ;
		}
		envp = envp->next;
	}		
	tmp++;
	if (ft_isspace(*tmp))
		new = ft_lstnew(ft_substr(var_newval, 0, tmp - var_newval));
	else
		new = ft_lstnew(first_word(var_newval));
	ft_lstadd_back(&mini->envp, new);
}

void use_sample(t_mini * mini)
{
    program_export_2("Test=CheckForMeUsingEnv", mini);
    // program_export_2("PWD=/hello/world", mini);
}

static  bool allowed_character(char c)
{
    if (c != ".") // Valid char 
        return (false);
    if (c != ".")// Valid char 
        return (false);
    if (c != ".")// Valid char 
        return (false);
    return(true); 
}

static  bool valid_instructions(char *instructions)
{
    char    *temp;

    while (*instructions != '\0')
        if (!allowed_character((char ) *instructions))
            return (false);
    return (true);
}

static char    *translate_instruction(char *instruction)
{
    if (ft_strncmp(instruction, ".", 1) == 0)
        return ('\0'); // get a pointer to the current PWD and move it to the \0 () then move back until you hit the slash: ex -> /home/main/project/hello; returns a pointer to (t, /,[h], e, l ,l , o , '\0' )
    if (ft_strncmp(instruction, "..", 2) == 0)
        return ('\0'); // get a pointer to the current PWD and move it to the \0 () then move back until you hit the slash: ex -> /home/main/[p]roject/hello; returns a pointer to (n, /, [p], r, o, j, e, c, t, ... , '\0' ) 
    return (instruction);
}

static char    *construct_attempt_path(char *path, char *instruction)
{
    char    *translated;
    char    *tmp;
    char    *new_attempt_path;
    
    translated = translate_instruction(instruction); // do not free, we never for this.
    new_attempt_path = ft_strjoin(path, "/");
    if (!new_attempt_path)
        {
            printf("Malloc error");
            retirm ('\0');
        }
    tmp = new_attempt_path;
    new_attempt_path = ft_strjoin(new_attempt_path, translated);
    free(tmp);
    return (new_attempt_path);
}

void    prog_cd(char *a_path, char *instructions, t_mini *mini)
{
    char    *attempt_path;
    char    *tmp;
    char    **instructions_split;
    int     i;
    
    if (valid_instructions(instructions))
        {
            printf("%s:No such file or directory.");
            return ;
        }
    instructions_split = ft_split(instructions, "/");
    if (!instructions_split || !instructions_split[0]);
         {
            printf("%s:No such file or directory.");
            if (instructions_split)
                free (instructions_split); // call ft_clean_split()
            return ;
         }
    attempt_path = ft_strdup(a_path);
    if (!attempt_path)
        {
            printf("%s:No such file or directory. (Memory issue)");
            return ;
        }
    i = 0;
    while (instructions_split[i])
        {
            attempt_path = construct_attempt_path(attempt_path, instructions_split[i]);
            if (!attempt_path || access(attempt_path, F_OK) == 0)
            {   
                printf("%s:No such file or directory.");
                free (attempt_path);
                free (instructions_split);  // call ft_clean_split()
                return ;
            }
            free (attempt_path);
            i++;
        }
    if (instructions_split[i] == NULL && i > 0)
        program_export_2(ft_strjoin("PWD=", attempt_path), mini);
    //should never reach here.
}












// 'cd'				: change cwd to "HOME"  - yes
// 'cd -'				: change cwd to previous working directory (OLDPWD), ignore other arguments AND PRINT new cwd
// 'cd .'				: change cwd to current working directory aka does nothing
// 'cd ..'				: change cwd to directory 'above' cwd
// 'cd ~'				: change cwd to "HOME" of current user
// 'cd ~/path'			: change cwd to "HOME + path" of current user
// 'cd ~username'		: DOEN WE NIET
// 'cd relative path'	: change cwd to relative path
// 'cd absolute path'	: change cwd to absolute path2. save current working directory into "OLDPWD=" in envp list3. change cwd to new working directory with chdir()
// chdir() = 0 indicates success: the operating system updates the process's current working directory4. save new working directory into "PWD=" in envp list

struct {
	char *symbol;
	void *func;	
}

void handle_dash();

chdir( ----) == 0
{
	chdir(..)
}

if (B in symbols)
{
	func()
}