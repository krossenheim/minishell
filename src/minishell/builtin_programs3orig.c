/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   builtin_programs3orig.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jose-lop <jose-lop@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/11 12:17:50 by diwang        #+#    #+#                 */
/*   Updated: 2024/09/27 14:35:33 by diwang        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	ft_strchr_backwards(const char *s, int c)  // abcdefghijk  11
{
	int				i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] >= 0)
	{
		if ((char) s[i] == (char) c)
			return (i);
		i--;
	}
	return (0);
}

static char	*get_pwd(t_mini *mini) // return everything after PWD= 
{
	char	*path;
	t_list	*tmp;

	tmp = mini->envp;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
		{
			path = tmp->content + 4;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static void	update_old_pwd(char **args, t_mini *mini) // take "current" PWD=, before changing and add/update it to OLDPWD=
{
	t_list *envp;
	char 	*pwd;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "OLDPWD=", 7) == 0)
			{	
				free(envp->content);
				pwd = get_pwd(mini);
				updated = ft_strjoin("OLDPWD=", pwd);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static char	*get_cd_path(t_list *envp_list) // for a few edge cases where you always return HOME
{
	char	*path;
	t_list	*tmp;

	tmp = envp_list;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "HOME=", 5) == 0)
		{
			path = tmp->content + 5;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static	void	update_pwd(char **args, t_mini *mini, char *path) // update the NEW pwd... user input, right?
{
	t_list *envp;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "PWD=", 4) == 0)
			{	
				free(envp->content);
				updated = ft_strjoin("PWD=", path);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static	char	*ft_updated_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i] != (unsigned char)c && ptr[i] != '\0')
	{
		i++;
	}
	if (ptr[i] == (unsigned char)c)
	{
		return (&ptr[i]);
	}
	return (NULL);
}

// static void	ft_part_one_cd(char **args, t_mini *mini)
// {
// 	int		i;
// 	char	*home_dir;
// 	char	*confirm_path;
	
// 	if (chdir("..") == 0)
// 	{
// 		update_old_pwd(args, mini);
// 		home_dir = get_pwd(mini);
// 		i = ft_strchr_backwards(home_dir, '/');
// 		confirm_path = ft_substr(home_dir, 0, i);
// 		chdir(confirm_path);
// 		update_pwd(args, mini, confirm_path);
// 	}
// }

///*****USE THIS CODE *****///

static void	ft_part_one_cd(char **args, t_mini *mini)
{
	int		i;
	char	*home_dir;
	char	*confirm_path;
	
	if (chdir("..") == 0)
	{
		printf("TESTING1\n");
		update_old_pwd(args, mini);
		home_dir = get_pwd(mini);
		i = ft_strchr_backwards(home_dir, '/');
		confirm_path = ft_substr(home_dir, 0, i);
		chdir(confirm_path);
		update_pwd(args, mini, confirm_path);
	}
	else
		perror("error with cd");
}


static void	ft_part_three_cd(char **args, t_mini *mini)
{
	char	*home_dir;
	//char	*confirm_path;
	char	*confirm_path1;
	char	*one_more;

	if (chdir(args[1]) == 0)
	{
		printf("TESTING2\n");
		update_old_pwd(args, mini);
		home_dir = get_pwd(mini);
		printf("%s\n", home_dir);
		//confirm_path = ft_strjoin(home_dir, "/");
		one_more = ft_updated_strchr(args[1], '/');
		printf("%s\n", one_more);
		confirm_path1 = ft_strjoin(home_dir, one_more);
		printf("%s\n", confirm_path1);
		update_pwd(args, mini, confirm_path1);
	}
	else
		perror("no such path");
}

static void	ft_part_four_cd(char **args, t_mini *mini)
{
	char	*confirm_path;
	
	printf("TESTING3\n");
	update_old_pwd(args, mini);
	confirm_path = get_cd_path(mini->envp);
	if (access(confirm_path, F_OK) == 0)
	{
		chdir(confirm_path);
		update_pwd(args, mini, confirm_path);
	}
	else
		perror("no such path");
}

static void	ft_part_five_cd(char **args, t_mini *mini)
{
	char	*pwd;
	char	*confirm_path;
	char	*confirm_path1;

	printf("TESTING4\n");
	update_old_pwd(args, mini);
	pwd = get_pwd(mini);
	confirm_path = ft_strjoin(pwd, "/");
	confirm_path1 = ft_strjoin(confirm_path, args[1]);
	// if (0 && confirm_path)
	// 	return ;
	if (access(args[1], F_OK) == 0)
	{
		chdir(args[1]);
		//update_pwd(args, mini, args[1]);
		update_pwd(args, mini, confirm_path1);
	}
	else
		perror("no such path");
}

// static void	ft_part_two_cd(char **args, t_mini *mini)
// {
// 	char	*home_dir;
// 	char	*confirm_path;
// 	char	*confirm_path1;

// 	update_old_pwd(args, mini);
// 	home_dir = get_pwd(mini);
// 	confirm_path = ft_strjoin(home_dir, "/");
// 	confirm_path1 = ft_strjoin(confirm_path, args[1]);
// 	if (access(confirm_path1, F_OK) == 0)
// 	{
// 		chdir(confirm_path1);
// 		update_pwd(args, mini, confirm_path1);
// 	}
// 	else
// 		perror("no such path");
// }

void	program_cd(t_mini *mini)
{
	char	**args;
	char	*confirm_path1;

	confirm_path1 = NULL;	
	if( 0 && confirm_path1)
		return ;
	args = mini->to_exec->args;
	if (mini->to_exec->argc > 2)
		perror("too many arguments");
	if (ft_strncmp(args[0], "cd", 2) == 0 && ft_strlen(args[0]) == 2)
	{
		if (ft_strncmp(args[1], "..", 2) == 0 && ft_strlen(args[1]) == 2)  // moves one directory back with user typing "cd .."
			ft_part_one_cd(args, mini);
		else if (args[1] && (ft_strncmp(args[1], "./", 2) == 0)) // for when it's ./anything ??
			ft_part_three_cd(args, mini);
		else if ((mini->to_exec->argc == 1)
			&& (ft_strncmp(args[0], "cd", 2) == 0) && ft_strlen(args[0]) == 2) // goes to home with user types in CD
			ft_part_four_cd(args, mini);
		else if ((mini->to_exec->argc == 2)
			&& (ft_strncmp(args[1], "~", 1) == 0) && ft_strlen(args[1]) == 1) // goes to home with user types in CD
			ft_part_four_cd(args, mini);
		else if (args[1])											// supposed to do everything else ?
			ft_part_five_cd(args, mini);
		else
			update_old_pwd(args, mini);
	}
}

// void	program_cd(t_mini *mini)
// {
// 	char	**args;
// 	char	*confirm_path1;

// 	confirm_path1 = NULL;	
// 	if (0 && confirm_path1)
// 		return ;
// 	args = mini->to_exec->args;
// 	if (mini->to_exec->argc > 2)
// 		perror("too many arguments");
// 	if (ft_strncmp(args[0], "cd", 2) == 0 && ft_strlen(args[0]) == 2)
// 	{
// 		// if (ft_strncmp(args[1], "..", 2) == 0 && ft_strlen(args[1]) == 2)  // moves one directory back with user typing "cd .."
// 		// 	ft_part_one_cd(args, mini);
// 		// if (args[1] && (ft_strncmp(args[1], "./", 2) == 0)) // for when it's ./anything ??
// 		// 	ft_part_three_cd(args, mini);
// 		if ((mini->to_exec->argc == 1)
// 			&& (ft_strncmp(args[0], "cd", 2) == 0) && ft_strlen(args[0]) == 2) // goes to home with user types in CD
// 			ft_part_four_cd(args, mini);
// 		else if (args[1])											// supposed to do everything else ?
// 			ft_part_five_cd(args, mini);
// 		else
// 			update_old_pwd(args, mini);
// 	}
// }


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


// 'cd -'				: change cwd to previous working directory (OLDPWD), ignore other arguments AND PRINT new cwd

// 'cd ~/path'			: change cwd to "HOME + path" of current user

// 'cd ~username'		: DOEN WE NIET // "we don't"


//code for cd (goes to home) and bug and error checking

// static void	ft_part_one_cd(char **args, t_mini *mini)
// {
// 	int		i;
// 	char	*home_dir;
// 	char	*confirm_path;
	
// 	update_old_pwd(args, mini);
// 	home_dir = get_pwd(mini);
// 	//home_dir = getcwd();
// 	i = ft_strchr_backwards(home_dir, '/');
// 	confirm_path = ft_substr(home_dir, 0, i);
// 	chdir(confirm_path);
// 	update_pwd(args, mini, confirm_path);
// }


// static void	ft_part_two_cd(char **args, t_mini *mini)
// {
// 	char	*home_dir;
// 	char	*confirm_path;
// 	char	*confirm_path1;

// 	update_old_pwd(args, mini);
// 	home_dir = get_pwd(mini);
// 	confirm_path = ft_strjoin(home_dir, "/");
// 	confirm_path1 = ft_strjoin(confirm_path, args[1]);
// 	if (access(confirm_path1, F_OK) == 0)
// 	{
// 		chdir(confirm_path1);
// 		update_pwd(args, mini, confirm_path1);
// 	}
// 	else
// 		perror("no such path");
// }

// static void	ft_part_three_cd(char **args, t_mini *mini)
// {
// 	char	*home_dir;
// 	char	*confirm_path;
// 	char	*confirm_path1;
// 	char	*one_more;

// 	update_old_pwd(args, mini);
// 	home_dir = get_pwd(mini);
// 	confirm_path = ft_strjoin(home_dir, "/");
// 	one_more = ft_strchr(args[1], '/');
// 	confirm_path1 = ft_strjoin(confirm_path, one_more);
// 	if (access(confirm_path1, F_OK) == 0)
// 	{
// 		chdir(confirm_path1);
// 		update_pwd(args, mini, confirm_path1);
// 	}
// 	else
// 		perror("no such path");
// }

//way overcomplicated this LOLOLOL.

//use getcwd
//if it goes in just update PWD to get cwd in some instances?

	// else if (args[1] && (ft_strncmp(args[1], ".", 1) != 0))           // 
		// 	ft_part_two_cd(args, mini);



		#include "minishell.h"

// static	char	*ft_updated_strchr(const char *s, int c)
// {
// 	int		i;
// 	char	*ptr;

// 	i = 0;
// 	ptr = (char *)s;
// 	while (ptr[i] != (unsigned char)c && ptr[i] != '\0')
// 	{
// 		i++;
// 	}
// 	if (ptr[i] == (unsigned char)c)
// 	{
// 		return (&ptr[i]);
// 	}
// 	return (NULL);
// }

static char	*get_pwd(t_mini *mini) // return everything after PWD= 
{
	char	*path;
	t_list	*tmp;

	tmp = mini->envp;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "PWD=", 4) == 0)
		{
			path = tmp->content + 4;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static void	update_old_pwd(char **args, t_mini *mini) // take "current" PWD=, before changing and add/update it to OLDPWD=
{
	t_list *envp;
	char 	*pwd;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "OLDPWD=", 7) == 0)
			{	
				free(envp->content);
				pwd = get_pwd(mini);
				updated = ft_strjoin("OLDPWD=", pwd);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static char	*get_cd_path(t_list *envp_list) // for a few edge cases where you always return HOME
{
	char	*path;
	t_list	*tmp;

	tmp = envp_list;
	path = NULL;
	while (tmp != NULL)
	{
		if (ft_strncmp(tmp->content, "HOME=", 5) == 0)
		{
			path = tmp->content + 5;
			break ;
		}
		tmp = tmp->next;
	}
	return (path);
}

static	void	update_pwd(char **args, t_mini *mini, char *path) // update the NEW pwd... user input, right?
{
	t_list *envp;
	char	*updated;

	envp = mini->envp;
	if (ft_strncmp(args[0], "cd", 2) == 0)
	{
		while (envp)
		{
			if (ft_strncmp(envp->content, "PWD=", 4) == 0)
			{	
				free(envp->content);
				updated = ft_strjoin("PWD=", path);
				envp->content = ft_strdup(updated);
				free(updated);
				return ;
			}
			envp = envp->next;
		}		
	}
}

static void	ft_for_home_cd(char **args, t_mini *mini)
{
	char	*confirm_path;

	update_old_pwd(args, mini);
	confirm_path = get_cd_path(mini->envp);
	if (access(confirm_path, F_OK) == 0)
	{
		chdir(confirm_path);
		update_pwd(args, mini, confirm_path);
	}
	else
		perror("no such path");
}

// static void	ft_part_three_cd(char **args, t_mini *mini)
// {
// 	char	*home_dir;
// 	char	*confirm_path1;
// 	char	*one_more;

// 	//printf("with a slash ./\n");
// 	if (chdir(args[1]) == 0)
// 	{
// 		update_old_pwd(args, mini);
// 		home_dir = get_pwd(mini);
// 		one_more = ft_updated_strchr(args[1], '/');
// 		confirm_path1 = ft_strjoin(home_dir, one_more);
// 		update_pwd(args, mini, confirm_path1);
// 	}
// 	else
// 		perror("no such path");
// }

// static void	helper_program_pwd()
// {
// 	char buffer[1000];
// 	char *buf;
	
// 	buf = getcwd(buffer, 1000);
// 	if (buf == NULL)
// 	{
// 		free(buf);
// 		return ;
// 	}
// 	printf("%s\n", buffer);
// }

static char	*helper_program_pwd()
{
	char buffer[1000];
	char *buf;
	
	buf = getcwd(buffer, 1000);
	if (buf == NULL)
	{
		free(buf);
		return (0);
	}
	printf("%s\n", buffer);
	return (buf);
}

static void	ft_everything_cd(char **args, t_mini *mini)
{
	char *buf;
	printf("EVERYTHING\n");
	update_old_pwd(args, mini);
	if (access(args[1], F_OK) == 0)
	{
		chdir(args[1]);
		buf = helper_program_pwd();
		update_pwd(args, mini, buf);
	}
	else
		perror("no such path");
}

void	program_cd(t_mini *mini)
{
	char	**args;
	char	*confirm_path1;

	confirm_path1 = NULL;	
	if (0 && confirm_path1)
		return ;
	args = mini->to_exec->args;
	if (mini->to_exec->argc > 2)
		perror("too many arguments");
	if (ft_strncmp(args[0], "cd", 2) == 0 && ft_strlen(args[0]) == 2)
	{
		if ((mini->to_exec->argc == 1)
			&& (ft_strncmp(args[0], "cd", 2) == 0) && ft_strlen(args[0]) == 2) 
			ft_for_home_cd(args, mini);
		// else if (args[1] && (ft_strncmp(args[1], "./", 2) == 0)) // for when it's ./anything ??
		// 	ft_part_three_cd(args, mini);
		else if (args[1])											
			ft_everything_cd(args, mini);
		else
			update_old_pwd(args, mini);
	}
}