#include "../include/42sh.h"
#define WRITE_END 1
#define READ_END 0
#define STDOUT 1
#define STDIN 0

int		execute_cmd(t_command  *cmd, t_terminal *t)
{
	pid_t  pid;
	int status;

	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0){
	  execve(cmd->command, cmd->arguments, t->env);
	  exit(0);
	}
	else
	{
		if (waitpid(pid, &status, 0) > 0)
		{
			if (WIFEXITED(status) && !WEXITSTATUS(status))
				printf("program execution successfull\n");
			else if (WIFEXITED(status) && WEXITSTATUS(status))
				if (WEXITSTATUS(status) == 127)
					printf("exec failed\n");
			else
			   printf("err: FAILURE\n");
		else
		   printf("waitpid() failed\n");
		}
	}
	return (0);
}

int		piper(t_command *cmd, t_terminal *t, int fd[2], int alt)
{
	int		pid;
	int		status;

	if (!cmd)
		return (1);
	pid = fork();
	if (pid < 0)
		return (ft_printf_err("FORK CREATION FAILED\n"));
	if (pid == 0)
	{
		if (cmd->prev && cmd->prev->todo == 5)
		{
			dup2(fd[READ_END], STDIN);
			close(fd[0]);
			close(fd[1]);
		}
		if (cmd->todo == 5)
		{
			dup2(fd[WRITE_END], STDOUT);
			close(fd[0]);
			close(fd[1]);
		}
		execvp(cmd->command, cmd->arguments);//, t->env);
	}
	else if (cmd->todo == 5)
		piper(cmd->next, t, fd, 1);
	else
	{
		wait(&status);
		if (alt == 1)
			return (1);
		exit(1);
	}
	return (0);
}

int		pipe_it(t_command *cmd, t_terminal *t)
{
	int		fd[2];

	if (pipe(fd) == -1)
		ft_printf_err("pipe_err\n");
	piper(cmd, t, fd, 0);
	return (1);
}

int		run_commands(t_command *root, t_terminal *t)
{
	t_command	*buf;

	if (!root)
		return (0);
	buf = root;
	if (buf->todo > 0 && buf->todo < 5)
		execute_cmd(buf, t);
	if (buf->todo == 5)
		pipe_it(buf, t);
	//if 1 or 2 or 3, run and next
	//if 4, if first fails next, else next next
	//if 5, pipe then next, if next is 1 2 or 3, exec next
	return (1);
}













