// static void	child_process(t_mini *mini, int prev_fd, t_hell  *head)
// {
// 	int		fd[2];
// 	char	**envp;
// 	pid_t   pid;

// 	if (head->next != NULL)
//     	if (pipe(fd) == -1)
//         	perror("pipe");
//     	pid = fork();
//         if (pid == -1)
//             perror("fork");
// 	if (pid == 0) 
// 	{
// 		if (prev_fd != -1)
// 		{
// 			if (dup2(prev_fd, STDIN_FILENO) == -1)
// 				perror("dup2 prev_fd");
// 			close(prev_fd); 
// 		}
// 		if (head->next != NULL)
// 		{
// 			close(fd[0]);  
// 			if (dup2(fd[1], STDOUT_FILENO) == -1)
// 				perror("dup2 fd[1]");
// 			close(fd[1]); 
// 		}
// 		ft_redirecs(head);
// 		envp = envp_get(mini);
// 		if (execve(head->path, head->args, envp) == -1)
// 		{
// 			perror("child execve");
// 			free_split_contents(envp);
// 			free(envp);
// 			exit(0);
// 		}
// 	}
// 	else  
// 	{
// 		waitpid(pid, NULL, 0);
// 		if (prev_fd != -1)
// 			close(prev_fd);
// 		if (head->next != NULL)
// 		{
// 			close(fd[1]);  
// 			prev_fd = fd[0];  
// 		}
// 		dup2(mini->saved_stdout, STDOUT_FILENO);
// 		dup2(mini->saved_stdin, STDIN_FILENO);
// 	}
	
//}

// int execution(t_mini *mini)
// {
//     t_hell  *head;
//     //int     fd[2];        
//     int     prev_fd;
//     //pid_t   pid;
//    	//char    **envp;
	
// 	prev_fd = -1;
// 	mini->saved_stdout = dup(STDOUT_FILENO);
// 	mini->saved_stdin = dup(STDIN_FILENO); 
//     head = mini->to_exec;  
//     while (head != NULL)
//     {
//         if (!head->path && !is_builtin(head))
//             printf("Command '%s' not found.\n", head->args[0]);
// 		if (is_builtin(head) == 1)
// 			ft_is_builtin(head, mini);
//         else 
//         {
//             // if (head->next != NULL)
//             //     if (pipe(fd) == -1)
//             //         perror("pipe");
//             // pid = fork();
//             // if (pid == -1)
//             //     perror("fork");
// 			child_process(mini, prev_fd, head);
//             // if (pid == 0) 
// 			// {
            //     if (prev_fd != -1)
            //     {
            //         if (dup2(prev_fd, STDIN_FILENO) == -1)
            //             perror("dup2 prev_fd");
            //         close(prev_fd); 
            //     }
            //     if (head->next != NULL)
            //     {			if (head->infile > 0)
			// {
			// 	if (dup2(head->infile, STDIN_FILENO) == -1)
			// 		perror("Dup2 error infile");
			// }
			// if (head->outfile > 0) 
			// {
			// 	if (dup2(head->outfile, STDOUT_FILENO) == -1)
			// 		perror("Dup2 error outfile");
			// }
            //             perror("dup2 fd[1]");
            //         close(fd[1]); 
            //     }
			// 	ft_redirecs(head);
            //     envp = envp_get(mini);
            //     if (execve(head->path, head->args, envp) == -1)
            //     {
            //         perror("child execve");
			// 		free_split_contents(envp);
			// 		free(envp);
			// 		exit(0);
            //     }
            // }
            // else  
            // {
            //     waitpid(pid, NULL, 0);
            //     if (prev_fd != -1)
            //         close(prev_fd);
            //     if (head->next != NULL)
            //     {
            //         close(fd[1]);  
            //         prev_fd = fd[0];  
            //     }
           	// 	dup2(mini->saved_stdout, STDOUT_FILENO);
        	// 	dup2(mini->saved_stdin, STDIN_FILENO);
            // }
//         }
// 		if (head->infile > 0)
// 			close(head->infile);
// 		if (head->outfile > 0)
// 			close(head->outfile);
//         head = head->next;
//     }
//     close(mini->saved_stdout);
//     close(mini->saved_stdin);
//     return 0;
// }



// int execution(t_mini *mini)
// {
//     t_hell  *head;
//     int     fd[2];        
//     int     prev_fd;
//     pid_t   pid;
//     char    **envp;

// 	prev_fd = -1;
// 	mini->saved_stdout = dup(STDOUT_FILENO);
// 	mini->saved_stdin = dup(STDIN_FILENO); 
//     head = mini->to_exec;  
//     while (head != NULL)
//     {
//         if (!head->path && !is_builtin(head))
//             printf("Command '%s' not found.\n", head->args[0]);
// 		if (is_builtin(head) == 1)
// 		{
// 			//ft_is_builtin(head, mini);
//             if (head->next != NULL)
//             {
// 				mini->to_exec->pipe = 1;
//                 if (pipe(fd) == -1)
// 					perror("pipe");
//                	if (dup2(fd[1], STDOUT_FILENO) == -1)
//                     perror("dup2 fd[1]");
//                 close(fd[1]);  
//                 prev_fd = fd[0];
// 			}
// 			if (head->infile > 0)
// 			{
// 				if (dup2(head->infile, STDIN_FILENO) == -1)
// 					perror("Dup2 error infile");
// 			}
// 			if (head->outfile > 0) 
// 			{
// 				if (dup2(head->outfile, STDOUT_FILENO) == -1)
// 					perror("Dup2 error outfile");
// 			}
// 			exec_builtin(head, mini);
//             dup2(mini->saved_stdout, STDOUT_FILENO);
//         	dup2(mini->saved_stdin, STDIN_FILENO);
//     	}
//         else
//         {
//             if (head->next != NULL)
// 			{
// 				mini->to_exec->pipe = 1;	
//                 if (pipe(fd) == -1)
//                     perror("pipe");
// 			}
//             pid = fork();
//             if (pid == -1)
//                 perror("fork");
//             if (pid == 0) 
// 			{
//                 if (prev_fd != -1)
//                 {
//                     if (dup2(prev_fd, STDIN_FILENO) == -1)
//                         perror("dup2 prev_fd");
//                     close(prev_fd); 
//                 }
//                 if (head->next != NULL)
//                 {
//                     close(fd[0]);
//                     if (dup2(fd[1], STDOUT_FILENO) == -1)
//                         perror("dup2 fd[1]");
//                     close(fd[1]); 
//                 }
// 				if (head->infile > 0)
// 					if (dup2(head->infile, STDIN_FILENO) == -1)
// 						perror("Dup2 error infile");
// 				if (head->outfile > 0) 
// 				{
// 					if (dup2(head->outfile, STDOUT_FILENO) == -1)
// 						perror("Dup2 error outfile");
//             	}
//                 envp = envp_get(mini);
//             	execve(head->path, head->args, envp);
// 				perror("child execve");
// 				free_split_contents(envp);
// 				(free(envp), exit(1));
//             }
//             else  
//             {
//                 if (prev_fd != -1)
//                     close(prev_fd);
//                 if (head->next != NULL)
//                 {
//                     close(fd[1]);  
//                     prev_fd = fd[0];  
//                 }
//             }
//         }
// 		if (head->infile > 0 && pid == 0)
// 			close(head->infile);
// 		if (head->outfile > 0 && pid == 0)
// 			close(head->outfile);
//         head = head->next;
//     }
// 	int status;
// 	int last;
//     int exit_pid = waitpid(-1, &status, 0);
// 	while (exit_pid != -1)
// 	{
// 		if (exit_pid == pid)
// 			last = status;
//     	exit_pid = waitpid(-1, &status, 0);
// 	}
//     close(mini->saved_stdout);
//     close(mini->saved_stdin);
//     return last;
// }

// int execution(t_mini *mini)
// {
//     t_hell  *head;
//     int     fd[2];        
//     int     prev_fd;
//     pid_t   pid;
//     char    **envp;

// 	prev_fd = -1;
// 	mini->saved_stdout = dup(STDOUT_FILENO);
// 	mini->saved_stdin = dup(STDIN_FILENO); 
//     head = mini->to_exec;  
//     while (head != NULL)
//     {
//         if (!head->path && !is_builtin(head))
//             printf("Command '%s' not found.\n", head->args[0]);
// 		if (is_builtin(head) == 1)
// 		{
// 			//ft_is_builtin(head, mini);
//             if (head->next != NULL)
//             {
// 				mini->to_exec->pipe = 1;
//                 if (pipe(fd) == -1)
// 					perror("pipe");
//                	if (dup2(fd[1], STDOUT_FILENO) == -1)
//                     perror("dup2 fd[1]");
//                 close(fd[1]);  
//                 prev_fd = fd[0];
// 			}
// 			if (head->infile > 0)
// 			{
// 				if (dup2(head->infile, STDIN_FILENO) == -1)
// 					perror("Dup2 error infile");
// 			}
// 			if (head->outfile > 0) 
// 			{
// 				if (dup2(head->outfile, STDOUT_FILENO) == -1)
// 					perror("Dup2 error outfile");
// 			}
// 			exec_builtin(head, mini);
//             dup2(mini->saved_stdout, STDOUT_FILENO);
//         	dup2(mini->saved_stdin, STDIN_FILENO);
//     	}
//         else
//         {
//             if (head->next != NULL)
// 			{
// 				mini->to_exec->pipe = 1;	
//                 if (pipe(fd) == -1)
//                     perror("pipe");
// 			}
//             pid = fork();
//             if (pid == -1)
//                 perror("fork");
//             if (pid == 0) 
// 			{
//                 if (prev_fd != -1)
//                 {
//                     if (dup2(prev_fd, STDIN_FILENO) == -1)
//                         perror("dup2 prev_fd");
//                     close(prev_fd); 
//                 }
//                 if (head->next != NULL)
//                 {
//                     close(fd[0]);
//                     if (dup2(fd[1], STDOUT_FILENO) == -1)
//                         perror("dup2 fd[1]");
//                     close(fd[1]); 
//                 }
// 				ft_redirecs(head);
//                 envp = envp_get(mini);
//             	execve(head->path, head->args, envp);
// 				perror("child execve");
// 				free_split_contents(envp);
// 				(free(envp), exit(1));
//             }
//             else  
//             {
//                 if (prev_fd != -1)
//                     close(prev_fd);
//                 if (head->next != NULL)
//                 {
//                     close(fd[1]);  
//                     prev_fd = fd[0];  
//                 }
//             }
//         }
// 		if (head->infile > 0 && pid == 0)
// 			close(head->infile);
// 		if (head->outfile > 0 && pid == 0)
// 			close(head->outfile);
//         head = head->next;
//     }
// 	int exit_code;
// 	exit_code = ft_exit_status(pid);
// 	// int status;
// 	// int last;
//     // int exit_pid = waitpid(-1, &status, 0);
// 	// while (exit_pid != -1)
// 	// {
// 	// 	if (exit_pid == pid)
// 	// 		last = status;
//     // 	exit_pid = waitpid(-1, &status, 0);
// 	// }
//     close(mini->saved_stdout);
//     close(mini->saved_stdin);
// 	//printf("exit code: %i\n", last);
//     //return (last);
// 	printf("exit code: %i\n", exit_code);
// 	return (exit_code);
// }