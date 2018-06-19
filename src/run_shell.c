#include "../include/42sh.h"

int		run_shell(t_terminal	*t)
{
	char		*input;
	char		**splt;
	t_command	*root;
	//char	c[4];

	t->cmds = create_stack();
	while (1)
	{
		input = 0;
		ft_putstr_fd(COOL_RED, 1);
		input = prompt_command(t, PROMPT_MSG);
		if (input && input[0] != 0)
			push(t->cmds, 0, input);
		if (!input)
			break ;
	//	ft_printf("\noutput: %s\n", input);
		input = replace_wc(input);
		remove_backslash(&input);
		//add space if strstr commands (&&, || |);
		splt = split_and_rejoin(input);
		root = create_cmd(splt, 0);
		run_commands(root, t);
		//splt
		//order commands
		//run commands
	}
	return (0);
}
