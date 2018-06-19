#include "../include/42sh.h"

int		write_it(t_command *cmd, t_terminal *t, int flags, int std)
{
	pid_t  pid;
	int status;
	int fd;

	if (cmd->next)
		fd = open(cmd->next->command, flags, 0777);
	else
		return (ft_printf_err("no file to output to\n"));
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(fd, std);
		execvp(cmd->command, cmd->arguments);//, t->env);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	t += 1 -1 ;
	return (0);

}

int		read_it(t_command *cmd, t_terminal *t, int flags)
{
	pid_t  pid;
	int status;
	int fd;

	if (cmd->next)
		fd = open(cmd->next->command, flags, 0777);
	else
		return (ft_printf_err("no file to output to\n"));
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
	{
		dup2(fd, 0);
		execvp(cmd->command, cmd->arguments);//, t->env);
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
	t += 1 -1 ;
	return (0);

}
